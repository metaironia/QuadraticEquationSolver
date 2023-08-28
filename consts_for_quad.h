#ifndef CONSTS_FOR_QUAD_H_INCLUDED
#define CONSTS_FOR_QUAD_H_INCLUDED

/*! \defgroup GenConst General consts
    @{
*/

/// This is definition of ANSI escape code that makes text color red.
#define RED "\x1b[31;1m"

/// This is definition of ANSI escape code that makes text color white.
#define NORMAL "\x1b[0m"

/// This is definition of ANSI escape code that makes text color cyan.
#define CYAN "\x1b[36;1m"

/// This is definition of ANSI escape code that makes text color red for errors.
#define YELLOW "\x1b[33;1m"

/// This is the precision to compare floating point numbers.
const double EPS = 1E-10;

/// This is the max length of string of user's answer.
const int STLEN = 2;

/// This is the null precision to classify input errors.
const int PRECISION_ZERO = 0;

/// This is the max precision that user can input.
const int PRECISION_MAX = 10;

/// This is the max attempts user can input wrong answer.
const int MAX_ATTEMPTS = 3;

/// This is mark for quit program.
const int QUIT_MARK = 'q';

/// This is mark for ENTER.
const int ENTER = '\n';

/// This is mark for SPACE.
const int SPACE = ' ';

/**
    This enum contains number of roots of the quadratic equation.
*/
enum RootsQuantity {
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS
};

/**
    This enum contains numeric representation of user's answer.
*/
enum UserAnswer {
    NO = 0,
    YES
};


/**
    This enum contains numeric representation of each coefficient to classify input errors.
*/
enum Coeffs {
    NO_COEFF = 0,
    FIRST_COEFF,               ///< This is numeric representation of coefficient A.
    SECOND_COEFF,              ///< This is numeric representation of coefficient B.
    THIRD_COEFF                ///< This is numeric representation of coefficient C.
};

/**
    This struct contains all parameters of the quadratic equation.
*/
struct CoeffAndRoots {
    enum RootsQuantity nRoots; ///< This is number of roots of the quadratic equation.
    int precision;             ///< This is precision of roots of the quadratic equation.
    double a;                  ///< This is coefficient A of the quadratic equation.
    double b;                  ///< This is coefficient B of the quadratic equation.
    double c;                  ///< This is coefficient C of the quadratic equation.
    double x_1;                ///< This is first root of the quadratic equation.
    double x_2;                ///< This is second root of the quadratic equation.
};

/**
    @}
*/

#endif

