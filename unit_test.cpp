#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "consts_for_quad.h"
#include "solver_math_operation.h"

#include "unit_test.h"
#include "unit_test_vivod.h"
#include "unit_test_vvod.h"

extern CoeffAndRoots Quadr;

CoeffAndRoots EqMathCoeffsReff[MAX_NUMBER_TEST] {
    {INFINITE_ROOTS, 5, .a = 0  ,  0  ,  0  , NAN , NAN},
    {ONE_ROOT      , 5, .a = 1  ,  2  ,  1  , -1  , NAN},
    {TWO_ROOTS     , 5, .a = 1  ,  1  ,  0  , -1  , 0  },
    {NO_ROOTS      , 5, .a = 1  ,  1  ,  1  , NAN , NAN}
};

int UnitTestMain (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef) {

    assert (EqMathCoeffs != NULL);
    assert (EqMathCoeffsRef != NULL);

    int test_number = TEST_NUMBER_NULL;
    char user_input[STR_LEN] = "";

    UnitTestConsts test_state = TEST_STATE_NULL;


    if (!UnitTestInput (&test_number, user_input)) {

        return 0;
    }

    bool is_correct_str = !strcmp (user_input, "a");
    bool is_correct_test = (test_number != TEST_NUMBER_NULL);

    assert ( is_correct_str ||  is_correct_test);
    assert (!is_correct_str || !is_correct_test);

    if (is_correct_str) {

        TestAll (EqMathCoeffs, EqMathCoeffsRef, &test_state);
        return 0;

    } else if (is_correct_test) {

        TestOne (EqMathCoeffs, EqMathCoeffsRef, test_number, &test_state);
        return 0;
    }

    return -1;
}

void TestOne (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef,
              int test_number, UnitTestConsts *test_state) {

    assert (test_state != NULL);
    assert (EqMathCoeffs != NULL);
    assert (EqMathCoeffsRef != NULL);
    assert (test_number <= MAX_NUMBER_TEST - 1 && test_number >= 0);

    *EqMathCoeffs = {NO_ROOTS, PRECISION_ZERO, NAN, NAN, NAN, NAN, NAN};

    (EqMathCoeffs -> a) = (EqMathCoeffsRef[test_number].a);
    (EqMathCoeffs -> b) = (EqMathCoeffsRef[test_number].b);
    (EqMathCoeffs -> c) = (EqMathCoeffsRef[test_number].c);

    (EqMathCoeffs -> nRoots) = EqSolver (EqMathCoeffs);

    *test_state = TEST_FAILED;

    if (((EqMathCoeffs -> nRoots) == (EqMathCoeffsRef[test_number].nRoots)))  {

        switch (EqMathCoeffs -> nRoots) {
            case NO_ROOTS:
                *test_state = TEST_OK;
                break;

            case INFINITE_ROOTS:
                *test_state = TEST_OK;
                break;

            case ONE_ROOT:
                if (IsDoublesEqual ((EqMathCoeffs -> x_1),
                    (EqMathCoeffsRef[test_number].x_1))) {

                    *test_state = TEST_OK;
                }
                break;

            case TWO_ROOTS:
                if (IsDoublesEqual ((EqMathCoeffs -> x_1),
                    (EqMathCoeffsRef[test_number].x_1))) {

                    if (IsDoublesEqual ((EqMathCoeffs -> x_2),
                        (EqMathCoeffsRef[test_number].x_2))) {

                        *test_state = TEST_OK;
                    }
                }
                break;

            default:
                fprintf (stderr, RED "Error has been occurred during solutions search.\n" NORMAL);
                assert (0);
        }
    }

    UnitTestOutput (EqMathCoeffs, EqMathCoeffsRef, test_number, test_state);
}

void TestAll (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef,
              UnitTestConsts *test_state) {

    assert (test_state != NULL);
    assert (EqMathCoeffs != NULL);
    assert (EqMathCoeffsRef != NULL);

    for (int test_number = 0; test_number < MAX_NUMBER_TEST; test_number++) {

        assert (test_number >= 0 || test_number < MAX_NUMBER_TEST);

        TestOne (EqMathCoeffs, EqMathCoeffsRef, test_number, test_state);

    /*     if (*test_state == TEST_FAILED) {
            break;
        } */
    }
}

