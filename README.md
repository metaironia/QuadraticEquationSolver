# Quadratic equation solver

This program can solve quadratic equations.

## Getting started

### Makefile

To make executable file:
	make

To clean .o and executable files:
	make [clean]

To use makefile:
- Open the Command Prompt
- type "cd %folder with this project%"
- type "make" to make .o and executable file or "make clean" to clean .o and executable files

### Program usage:

Getting help:

```
$ kvadr [-h|--help]
```
Running tests:

```
$ kvadr [-t|--unit_test]
```

Solving equation A * x^2 + B * x + C = 0 with <Prec> as number of digits after decimal dot:

```
kvadr <A> <B> <C> <Prec>
```

Examples:
`$ kvadr 1 0 -4 2`  --- to solve x^2 - 4 = 0         with precision 0.01
`$ kvadr 5 2 -1 3`  --- to solve 5*x^2 + 2*x - 1 = 0 with precision 0.001

## Documentation

To make documentation to this program:
- run DoxyWizard;
- Click File -> Open -> choose "Doxyfile" from this project;
- Click Run -> Run doxygen -> Show HTML input.

## Author
Sergey Kulagin, MIPT 1-year student	
		