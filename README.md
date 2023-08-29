# Quadratic equation solver

This program can solve quadratic equations.

## Getting started

### Makefile

To use makefile:
- Open the Command Prompt
- type `$ cd %project folder%`
- type `$ make` to make .o and executable file or `$ make clean` to clean .o and executable files

### Program usage:

Getting help:

```
$ kvadr [-h|--help]
```
Running tests:

```
$ kvadr [-t|--unit_test]
```

Solving equation A * x^2 + B * x + C = 0 with `<Prec>` as number of digits after decimal dot:

```
$ kvadr <A> <B> <C> <Prec>
```

**Examples:**

To solve x^2 - 4 = 0 with precision 0.01
```
$ kvadr 1 0 -4 2  
```

To solve 5x<sup>2</sup> + 2x - 1 = 0 with precision 0.001:
```
$ kvadr 5 2 -1 3 
```

## Documentation

To make and see documentation to this program:
- run DoxyWizard;
- Click File -> Open -> choose "Doxyfile" from this project;
- Click Run -> Run doxygen -> Show HTML input.

## Author
Sergey Kulagin, MIPT 1-year student	
		