#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


void solve_tridiagonal_in_place_reusable ( double x[],double a,double b,double c, int N);
double f(double x)
{
    double s;
    return s = 10 * exp(-(pow((x-100),2))*(1./(2*10*10)));
}



void main()
{

    FILE *arq;
    arq = fopen("radiacao_est.txt", "w+");


    double S,s,estado_novo[401],a,b,c,k;
    int i,j,jmax,t;

    k = 1;
    jmax = 401;
    S = 0.0002 ;


//condição inicial
    for (j = 1 ; j < jmax ; j++)
    {
        estado_novo[j] = f(j);

    }

//condições de contorno
    estado_novo[0] = 0;
    estado_novo[jmax-1] = 0;


    a = -k;
    b = S+2*k;
    c = -k;

estado_novo[1] = estado_novo[1] - k*estado_novo[0];
estado_novo[jmax-2] = estado_novo[jmax-2] - k*estado_novo[jmax-1];



solve_tridiagonal_in_place_reusable(estado_novo,a,b,c,jmax);



    for(j = 0 ; j < jmax ; j++)
    {

        fprintf(arq, "%d %lf\n", j,estado_novo[j]);
    }



    fclose(arq);

}

void solve_tridiagonal_in_place_reusable (double x[],double a,double b,double c, int N)

{

    double m;
    int n;


    double *cfinal;
    cfinal = malloc ( N * sizeof ( double )  ) ;

    cfinal [1] = c/ b;
    x [1] = x [1] / b;

    /* loop de 2 a N - 2 inclusive */
    for ( n = 2; n < N-1 ; n ++)
    {
        m = 1.0 / ( b  - ( cfinal[ n - 1] * a ) );
        cfinal [ n ] = c * m ;


        x [ n ] = ( x [ n ] - a  * x [ n - 1]) * m ;
    }


    /* loop de N - 2 a 0 exclusive */
    for (n = (N - 2) ; n > 0; n--)
    {
        x [ n ] = x [ n ] - cfinal [ n ] * x [ n + 1];
    }


    free ( cfinal );

}
