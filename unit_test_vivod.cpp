#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "consts_for_quad.h"
#include "unit_test.h"
#include "unit_test_vivod.h"

extern CoeffAndRoots Quadr;
extern CoeffAndRoots EqMathCoeffsReff;

void UnitTestOutput (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef,
                     int test_number, UnitTestConsts *test_state) {

    assert (EqMathCoeffs != NULL);
    assert (EqMathCoeffsRef != NULL);
    assert (test_state != NULL);
    assert (test_number > TEST_NUMBER_NULL && test_number < MAX_NUMBER_TEST);

    switch (*test_state) {
        case (TEST_FAILED):

            fprintf (stderr, RED "Test %d failed!\n"
                                 "If A = %lf, B = %lf è C = %lf expected result: "
                                 "x_1 = %lf, x_2 = %lf\n" NORMAL,
                                 test_number + 1,
                                 EqMathCoeffsRef[test_number].a, EqMathCoeffsRef[test_number].b,
                                 EqMathCoeffsRef[test_number].c, EqMathCoeffsRef[test_number].x_1,
                                 EqMathCoeffsRef[test_number].x_2);

            fprintf (stderr, RED "Program output: x_1 = %lf, x_2 = %lf\n" NORMAL, (EqMathCoeffs -> x_1),
                                                                                  (EqMathCoeffs -> x_2));
            break;

        case (TEST_OK):

            printf ("Test %d passed!\n"
                    "If A = %lf, B = %lf è C = %lf expected result: x_1 = %lf, x_2 = %lf\n",
                    test_number + 1,
                    EqMathCoeffsRef[test_number].a, EqMathCoeffsRef[test_number].b,
                    EqMathCoeffsRef[test_number].c, EqMathCoeffsRef[test_number].x_1,
                    EqMathCoeffsRef[test_number].x_2);

            printf ("Program output: x_1 = %lf, x_2 = %lf\n", (EqMathCoeffs -> x_1),
                                                                (EqMathCoeffs -> x_2));
            break;

        case TEST_STATE_NULL:
            fprintf (stderr, RED "Test state is null." NORMAL);
            assert(0);

        default:
            assert(0);
    }
}
