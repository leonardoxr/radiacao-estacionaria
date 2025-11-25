# Radiação Estacionária (Stationary Radiation)

> **Note:** This was a college project for a numerical methods or computational physics course. It's an educational implementation, so don't take it too seriously as production-ready code!

## Overview

This program solves a one-dimensional stationary radiation (or heat diffusion) problem using numerical methods. It implements a tridiagonal matrix solver (Thomas algorithm) to find the steady-state solution of a diffusion-like equation with a Gaussian-shaped initial/source distribution.

## What Does It Do?

The program:
1. Sets up a Gaussian-shaped source term centered at position 100
2. Applies boundary conditions (zero at both ends)
3. Solves a tridiagonal system of linear equations
4. Outputs the solution to a file for plotting/analysis

This type of problem commonly appears in:
- Heat diffusion simulations
- Quantum mechanics (stationary states)
- Radiation transport
- Computational physics courses

## Mathematical Background

The program solves a system that can be written as:

```
A * x = b
```

Where `A` is a tridiagonal matrix with:
- Main diagonal: `b = S + 2k`
- Upper/lower diagonals: `a = c = -k`

The boundary conditions are:
- `x[0] = 0`
- `x[400] = 0`

The source term is a Gaussian function:
```c
f(x) = 10 * exp(-(x-100)² / (2*10²))
```

## Requirements

- A C compiler (gcc, clang, etc.)
- Standard C libraries (stdio.h, math.h, stdlib.h, string.h)

## Compilation

Compile the program using gcc:

```bash
gcc radiacao_estacionario.c -o radiacao -lm
```

The `-lm` flag links the math library (required for `exp()` and `pow()` functions).

## Usage

Run the compiled program:

```bash
./radiacao
```

The program will generate an output file named `radiacao_est.txt` containing two columns:
- Column 1: Position index (0 to 400)
- Column 2: Solution value at that position

## Output

The output file `radiacao_est.txt` can be plotted using tools like:
- **gnuplot**: `plot "radiacao_est.txt" with lines`
- **Python/matplotlib**:
  ```python
  import numpy as np
  import matplotlib.pyplot as plt
  data = np.loadtxt('radiacao_est.txt')
  plt.plot(data[:, 0], data[:, 1])
  plt.xlabel('Position')
  plt.ylabel('Value')
  plt.show()
  ```
- **Excel/LibreOffice Calc**: Import as space-delimited data

## Algorithm Details

### Tridiagonal Matrix Solver (Thomas Algorithm)

The program uses the Thomas algorithm (a simplified form of Gaussian elimination) to solve the tridiagonal system efficiently in O(n) time:

1. **Forward sweep**: Eliminates the lower diagonal
2. **Backward substitution**: Solves for the unknowns

This is much more efficient than general matrix solvers for tridiagonal systems.

## Parameters

Key parameters in the code:
- `jmax = 401`: Number of grid points
- `S = 0.0002`: Source/stability parameter
- `k = 1`: Diffusion coefficient
- Gaussian center: position 100
- Gaussian width: σ = 10

## File Structure

```
radiacao-estacionaria/
├── radiacao_estacionario.c    # Main source code
├── README.md                   # This file
├── LICENSE                     # GPL v3 license
├── .gitignore                 # Git ignore patterns
└── radiacao_est.txt           # Output file (generated after running)
```

## Known Limitations

As a college project, this code has some quirks:
- No error handling for file operations
- Hard-coded parameters (no command-line arguments)
- Limited comments in the source code
- Uses `void main()` instead of `int main()` (not standard-compliant)
- Portuguese comments in source code
- Magic numbers throughout the code

## Contributing

This is an archived college project, but if you want to improve it for educational purposes:
1. Fork the repository
2. Make your changes
3. Submit a pull request

Potential improvements:
- Add command-line argument parsing
- Implement error handling
- Make parameters configurable
- Add visualization tools
- Improve code documentation
- Fix compiler warnings

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## Educational Context

This project was created as part of a university course assignment. It demonstrates:
- Numerical methods for solving PDEs
- Tridiagonal matrix algorithms
- Basic C programming
- File I/O operations
- Memory management in C

## Acknowledgments

- The Thomas algorithm implementation is a standard numerical method
- Gaussian source function is commonly used in physics simulations

---

**Disclaimer**: This is educational code from a college project. Use at your own risk for learning purposes!