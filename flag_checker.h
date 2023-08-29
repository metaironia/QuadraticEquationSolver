#ifndef FLAG_CHECKER_H_INCLUDED
#define FLAG_CHECKER_H_INCLUDED

#include "consts_for_quad.h"

/** \defgroup Flags Program flags
    @{
 */

/// This is the numeric representation of the situation when there is no command line arguments.
const int FIRST_ARG = 1;

/// This is the total amount of command line arguments.
const int NUM_OF_FLAGS = 2;

/// This is the max length of the command line argument name.
const int FLAG_STLEN = 20;

/**
    This struct contains all parameters of the command line arguments.
*/
struct AllFlags {
    char flag_name_l[FLAG_STLEN];           ///< This is the short name of command line argument.
    char flag_name_sh[FLAG_STLEN];          ///< This is the long name of command line argument.
    int (*FlagFunc) (void *args);           ///< This is the pointer to the function that corresponding to command line argument.
    void *args_address;                     ///< This is the pointer to the struct with arguments that corresponding to command line argument.
};

/**
    This function checks whether entered command line argument exists or not.
    @param [in] *argv[] the pointer to array of command line arguments.
    @param [in] argc a number of command line arguments.
    @param [in] *FlagsForCmd the pointer to AllFlags struct.
*/
void FlagChecker (char *const argv[], const int argc, AllFlags *const FlagsForCmd);

/**
    @}
*/

#endif
