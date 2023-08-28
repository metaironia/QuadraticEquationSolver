#ifndef VVOD_VIVOD_H_INCLUDED
#define VVOD_VIVOD_H_INCLUDED

#include "consts_for_quad.h"

/** \defgroup Main Main program */

/**
    \defgroup ForQuadraticIo Input and Output
    \ingroup Main
    @{
*/

/**
    Function that reads user's input A, B and C coefficients.
    @param [in, out] *EqMathCoeffs the pointer to CoeffAndRoots struct
    @see PrecisionInput()
*/
void CoeffInput (struct CoeffAndRoots *EqMathCoeffs);

/**
    Function that reads user's input precision.
    @param [in, out] *EqMathCoeffs the pointer to CoeffAndRoots struct
    @see CoeffInput()
*/
void PrecisionInput (struct CoeffAndRoots *EqMathCoeffs);

/**
    Function that reads user's input answer after equation was solved.
    @param [in, out] otvet array to read user's answer into.
    @return \p YES if user want to continue, \p NO if input is incorrect or user want to leave
*/
enum UserAnswer OtvetInput (char *otvet);

/**
    Function that clears stdin.
    @see VvodCheck()
*/
void VvodClear (void);

/**
    Function that checks if input value has correct format.
    @return 0 if input value has correct format, 1 if not
    @see VvodClear()
*/
int VvodCheck (void);

/**
    Function that outputs roots of the equation.
    @param [in] *EqMathCoeffs the pointer to CoeffAndRoots struct
    @see OtvetInput()
*/
void EqOutput (struct CoeffAndRoots *EqMathCoeffs);

/**
    @}
*/

#endif
