#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "consts_for_quad.h"
#include "unit_test.h"
#include "unit_test_vivod.h"

void UnitTestOutput (UnitArgsStruct *const arg_storage, const int test_number, UnitTestConsts test_state) {

    assert (arg_storage != NULL);
    assert ((arg_storage -> result_data) != NULL);
    assert ((arg_storage -> ref_data) != NULL);
    assert (test_number > TEST_NUMBER_NULL && test_number < MAX_NUMBER_TEST);

    switch (test_state) {
        case (TEST_FAILED):

            fprintf (stderr, RED "Test %d failed!\n"
                                 "If A = %lf, B = %lf and C = %lf expected result: "
                                 "x_1 = %lf, x_2 = %lf\n" NORMAL,
                                 test_number + 1,
                                 arg_storage -> ref_data[test_number].a,
                                 arg_storage -> ref_data[test_number].b,
                                 arg_storage -> ref_data[test_number].c,
                                 arg_storage -> ref_data[test_number].x_1,
                                 arg_storage -> ref_data[test_number].x_2);

            fprintf (stderr, RED "Program output: x_1 = %lf, x_2 = %lf\n" NORMAL,
                                 (arg_storage -> result_data -> x_1),
                                 (arg_storage -> result_data -> x_2));
            break;

        case (TEST_OK):

            printf ("Test %d passed!\n"
                    "If A = %lf, B = %lf and C = %lf expected result: x_1 = %lf, x_2 = %lf\n",
                    test_number + 1,
                    arg_storage -> ref_data[test_number].a,
                    arg_storage -> ref_data[test_number].b,
                    arg_storage -> ref_data[test_number].c,
                    arg_storage -> ref_data[test_number].x_1,
                    arg_storage -> ref_data[test_number].x_2);

            printf ("Program output: x_1 = %lf, x_2 = %lf\n",
                    (arg_storage -> result_data -> x_1),
                    (arg_storage -> result_data -> x_2));
            break;

        case TEST_STATE_NULL:
            fprintf (stderr, RED "Test state is null." NORMAL);
            assert(0);
            [[fallthrough]]

        default:
            assert(0);
    }
}
