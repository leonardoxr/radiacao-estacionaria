/*
 * Radiação Estacionária (Stationary Radiation Solver)
 *
 * This program solves a one-dimensional stationary radiation/diffusion problem
 * using a tridiagonal matrix solver (Thomas algorithm).
 *
 * Author: College project
 * License: GPL v3
 */

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

// Function prototype for tridiagonal solver
void solve_tridiagonal_in_place_reusable ( double x[],double a,double b,double c, int N);

/**
 * Gaussian source function
 *
 * Creates a Gaussian (bell curve) centered at x=100 with amplitude 10
 * and standard deviation (width) of 10.
 *
 * @param x Position along the grid
 * @return Gaussian value at position x
 */
double f(double x)
{
    double s;
    // Gaussian formula: A * exp(-(x-μ)² / (2σ²))
    // where A=10, μ=100, σ=10
    return s = 10 * exp(-(pow((x-100),2))*(1./(2*10*10)));
}



/**
 * Main function
 *
 * Sets up and solves a stationary radiation/diffusion problem:
 * 1. Initializes the system with a Gaussian source
 * 2. Applies boundary conditions
 * 3. Solves the tridiagonal system
 * 4. Writes results to file
 */
void main()
{
    // Open output file for writing results
    FILE *arq;
    arq = fopen("radiacao_est.txt", "w+");

    // Variable declarations
    double S,s,estado_novo[401],a,b,c,k;
    int i,j,jmax,t;

    // Parameters
    k = 1;          // Diffusion coefficient
    jmax = 401;     // Number of grid points (0 to 400)
    S = 0.0002 ;    // Source/stability parameter

    // Condição inicial (Initial condition)
    // Set up the Gaussian source distribution
    for (j = 1 ; j < jmax ; j++)
    {
        estado_novo[j] = f(j);

    }

    // Condições de contorno (Boundary conditions)
    // Fixed at zero on both ends
    estado_novo[0] = 0;
    estado_novo[jmax-1] = 0;

    // Tridiagonal matrix coefficients
    // The system is: a*x[i-1] + b*x[i] + c*x[i+1] = estado_novo[i]
    a = -k;         // Lower diagonal
    b = S+2*k;      // Main diagonal
    c = -k;         // Upper diagonal

    // Adjust boundary elements to incorporate boundary conditions
    estado_novo[1] = estado_novo[1] - k*estado_novo[0];
    estado_novo[jmax-2] = estado_novo[jmax-2] - k*estado_novo[jmax-1];

    // Solve the tridiagonal system using Thomas algorithm
    solve_tridiagonal_in_place_reusable(estado_novo,a,b,c,jmax);

    // Write solution to output file
    // Format: position value
    for(j = 0 ; j < jmax ; j++)
    {

        fprintf(arq, "%d %lf\n", j,estado_novo[j]);
    }

    // Close output file
    fclose(arq);

}

/**
 * Thomas Algorithm - Tridiagonal Matrix Solver
 *
 * Solves a tridiagonal system of linear equations in-place:
 *   a*x[i-1] + b*x[i] + c*x[i+1] = x[i]  (where x initially contains RHS)
 *
 * The algorithm works in O(n) time using:
 * 1. Forward elimination to remove lower diagonal
 * 2. Backward substitution to solve for unknowns
 *
 * @param x     Array containing RHS on input, solution on output (modified in-place)
 * @param a     Lower diagonal coefficient (constant for all rows)
 * @param b     Main diagonal coefficient (constant for all rows)
 * @param c     Upper diagonal coefficient (constant for all rows)
 * @param N     Size of the system
 *
 * Note: This assumes boundary conditions have already been applied to x[1] and x[N-2]
 */
void solve_tridiagonal_in_place_reusable (double x[],double a,double b,double c, int N)

{

    double m;
    int n;

    // Allocate temporary array for modified upper diagonal
    double *cfinal;
    cfinal = malloc ( N * sizeof ( double )  ) ;

    // Initialize first row
    cfinal [1] = c/ b;
    x [1] = x [1] / b;

    /* Forward elimination: loop from 2 to N-2 inclusive */
    // Eliminate lower diagonal and modify upper diagonal and RHS
    for ( n = 2; n < N-1 ; n ++)
    {
        m = 1.0 / ( b  - ( cfinal[ n - 1] * a ) );
        cfinal [ n ] = c * m ;

        x [ n ] = ( x [ n ] - a  * x [ n - 1]) * m ;
    }

    /* Backward substitution: loop from N-2 to 1 */
    // Solve for unknowns using modified system
    for (n = (N - 2) ; n > 0; n--)
    {
        x [ n ] = x [ n ] - cfinal [ n ] * x [ n + 1];
    }

    // Free temporary memory
    free ( cfinal );

}
