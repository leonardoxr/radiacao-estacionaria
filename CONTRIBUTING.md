# Contributing to Radiação Estacionária

Thank you for your interest in this project! While this is an archived college project, contributions for educational purposes are welcome.

## About This Project

This is a **college project** created for a numerical methods or computational physics course. The code is meant for educational purposes and demonstrates basic numerical algorithms in C.

## How to Contribute

If you'd like to improve this project for learning purposes, here's how:

### Getting Started

1. Fork the repository
2. Clone your fork:
   ```bash
   git clone https://github.com/YOUR-USERNAME/radiacao-estacionaria.git
   ```
3. Create a new branch:
   ```bash
   git checkout -b feature/your-improvement
   ```

### Making Changes

Some ideas for improvements:
- Add command-line argument parsing
- Implement error handling for file operations
- Add input validation
- Create visualization scripts (Python/gnuplot)
- Fix compiler warnings
- Improve code structure
- Add unit tests
- Translate Portuguese comments to English
- Add more documentation

### Code Style

When contributing, please:
- Keep the educational nature of the code
- Add comments explaining what your changes do
- Follow the existing code structure
- Test your changes by compiling and running the program

### Compilation Test

Before submitting, make sure your code compiles without errors:

```bash
gcc radiacao_estacionario.c -o radiacao -lm -Wall
```

And runs successfully:

```bash
./radiacao
```

### Submitting Changes

1. Commit your changes with a clear message:
   ```bash
   git add .
   git commit -m "Add feature: description of your changes"
   ```

2. Push to your fork:
   ```bash
   git push origin feature/your-improvement
   ```

3. Open a Pull Request on GitHub

### Pull Request Guidelines

In your pull request, please:
- Describe what changes you made
- Explain why the changes improve the project
- Mention any potential issues or trade-offs
- Include example output if applicable

## Reporting Issues

Found a bug or have a suggestion? Please:
1. Check if an issue already exists
2. Open a new issue with a clear description
3. Include:
   - What you expected to happen
   - What actually happened
   - Steps to reproduce (if it's a bug)
   - Your system info (OS, compiler version)

## Code of Conduct

### Be Respectful

- This is a learning project - be constructive in feedback
- Remember that everyone is here to learn
- Help others who might be new to C programming
- Be patient with questions

### Educational Focus

- Prioritize clarity over optimization
- Explain complex concepts in comments
- Share learning resources when relevant
- Celebrate learning moments

## Questions?

If you have questions about:
- **The code**: Open an issue with your question
- **The physics/math**: Include references to help others learn too
- **Contributing process**: Check GitHub's documentation or ask in an issue

## License

By contributing, you agree that your contributions will be licensed under the same GPL v3 license that covers this project.

---

Thank you for helping make this educational project better!
