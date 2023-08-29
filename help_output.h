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
    This is the struct with arguments for function HelpOutput().
*/
struct HelpArgsStruct {};

/**
    This function shows help.
    @param [in] *storage the pointer to struct with required arguments.
    @note \p *storage is not used in this function.
    @return always 0
    @attention This function has type "int" because of FlagChecker() requires it.
    @see FlagChecker()
*/
int HelpOutput (void *storage);

/**
    @}
*/

#endif
