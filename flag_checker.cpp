#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "consts_for_quad.h"
#include "unit_test.h"
#include "help_output.h"
#include "flag_checker.h"

extern CoeffAndRoots Quadr;
extern CoeffAndRoots EqMathCoeffsReff[];
extern HelpArgsStruct HelpArgs;
extern UnitArgsStruct UnitArgs;

AllFlags sFlagsForCmd[NUM_OF_FLAGS] {
    {"--unit_test", "-t", UnitTestMain, &UnitArgs},
    {"--help"     , "-h", HelpOutput  , &HelpArgs}
};

void FlagChecker (char *argv[], int argc, AllFlags *FlagsForCmd) {

    assert (argv != NULL);
    assert (FlagsForCmd != NULL);
    assert (argc >= FIRST_ARG + 1);

    int flag_read = 0;

    for (int curr_arg = FIRST_ARG; curr_arg < argc; curr_arg++) {

        assert (curr_arg >= FIRST_ARG && curr_arg < argc);

        for (int curr_flag = 0; curr_flag < NUM_OF_FLAGS; curr_flag++) {

            assert (curr_flag >= 0 && curr_flag < NUM_OF_FLAGS);

            if (!strcmp (FlagsForCmd[curr_flag].flag_name_l, argv[curr_arg])) {

                flag_read++;
                FlagsForCmd[curr_flag].FlagFunc (FlagsForCmd -> args_address);
            }

            if (!strcmp (FlagsForCmd[curr_flag].flag_name_sh, argv[curr_arg])) {

                flag_read++;
                FlagsForCmd[curr_flag].FlagFunc (FlagsForCmd -> args_address);
            }
        }
    }

    if (flag_read == 0) {

        fprintf (stderr, RED "This argument does not exist. Program was finished.\n" NORMAL);
    }
}
