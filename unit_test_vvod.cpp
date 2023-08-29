#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "unit_test.h"

#include "consts_for_quad.h"
#include "unit_test_vvod.h"
#include "vvod_vivod.h"

int UnitTestInput (int *test_number, char *user_input) {

    assert (test_number != NULL);
    assert (user_input  != NULL);

    int scanf_status = 0;

    printf ("Enter the number of test from 1 to %d,\n"
            "Or enter \"a\" to run all tests:\n", MAX_NUMBER_TEST);

    for (int attempts = 0; attempts < MAX_ATTEMPTS; attempts++) {

        if ((scanf_status = scanf ("%d", test_number)) == 1 && !VvodCheck()) {

            if (*test_number > MAX_NUMBER_TEST || *test_number < 1) {

                fprintf (stderr, RED "Entered number of test is incorrect!"
                                     "Remaining attempts: %d\n" NORMAL,
                                      MAX_ATTEMPTS - attempts - 1);

                VvodClear();
                continue;

            } else {

                *test_number -= 1;
                return 1;
            }
        }

        if (!scanf_status) {

            if ((user_input[0] = (char) (tolower (getchar()))) == ALL_TESTS_MARK &&
                !VvodCheck()) {

                user_input[1] = '\0';
                return 1;
            }
        }
        if (attempts != MAX_ATTEMPTS - 1)
            fprintf (stderr, RED "Enter the correct input! "
                                 "Remaining attempts: %d\n" NORMAL,
                                  MAX_ATTEMPTS - attempts - 1);
        else
            printf ("Program was finished.\n");

        VvodClear();
    }
    return 0;
}
