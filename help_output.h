#ifndef HELP_OUTPUT_H_INCLUDED
#define HELP_OUTPUT_H_INCLUDED

#include <assert.h>
#include "consts_for_quad.h"

/**
    \defgroup HelpFlag Help flag
    \ingroup Flags
    @{
*/

/**
    This function shows help.
    @param [in] *EqMathCoeffs the pointer to CoeffAndRoots struct.
    @param [in] *EqMathCoeffsRef the pointer to CoeffAndRoots struct with reference data.
    @note \p *EqMathCoeffs and \p *EqMathCoeffsRef are not used in this function.
    @return always 0
    @attention This function has type "int" because of FlagChecker() requires it.
    @see FlagChecker()
*/
int HelpOutput (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef);

/**
    @}
*/

#endif
