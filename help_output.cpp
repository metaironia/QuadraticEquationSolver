#include <stdio.h>

#include "help_output.h"

HelpArgsStruct HelpArgs {};

int HelpOutput (void *const storage) {

    assert (storage != NULL);
   // HelpArgsStruct *arg_storage;
   // arg_storage = (HelpArgsStruct *) storage;

    printf (CYAN "This program can solve quadratic equations.\n\n"

            "Usage:\n\n"

            "Getting help:\n"
            "       kvadr [-h|--help]\n\n"

            "Running tests:\n"
            "       kvadr [-t|--unit_test]\n\n"

            "Solving equation A * x^2 + B * x + C = 0 with <Prec> as number of digits after decimal dot:\n"
            "       kvadr <A> <B> <C> <Prec>\n\n"

            "Examples:\n"
            "       kvadr 1 0 -4 2  --- to solve x^2 - 4 = 0         with precision 0.01\n"
            "       kvadr 5 2 -1 3  --- to solve 5*x^2 + 2*x - 1 = 0 with precision 0.001\n" NORMAL);

    return 0;
}
