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
    {INFINITE_ROOTS, 1, .a = 0  ,  0  ,  0  ,  NAN , NAN},
    {ONE_ROOT      , 1, .a = 1  ,  2  ,  1  ,  -1  , NAN},
    {TWO_ROOTS     , 1, .a = 1  ,  1  ,  0  ,  -1  ,  0 },
    {NO_ROOTS      , 1, .a = 1  ,  1  ,  1  ,  NAN , NAN},
    {TWO_ROOTS     , 1, .a = 2  , -1  , -1  , -0.5 ,  1 },
    {TWO_ROOTS     , 1, .a = 1  ,  5  ,  6  ,  -3  , -2 },
};

UnitArgsStruct UnitArgs {
    EqMathCoeffsReff,
    &Quadr
};

int UnitTestMain (void *const storage) {

    assert (storage != NULL);

    UnitArgsStruct *arg_storage;
    arg_storage = (UnitArgsStruct *) storage;

    assert (arg_storage != NULL);
    assert ((arg_storage -> result_data) != NULL);
    assert ((arg_storage -> ref_data) != NULL);

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

        TestAll (arg_storage, &test_state);
        return 0;

    } else if (is_correct_test) {

        TestOne (arg_storage, test_number, &test_state);
        return 0;
    }

    return -1;
}

void TestOne (UnitArgsStruct *arg_storage, const int test_number, UnitTestConsts *const test_state) {

    assert (test_state != NULL);
    assert (arg_storage != NULL);
    assert ((arg_storage -> result_data) != NULL);
    assert ((arg_storage -> ref_data) != NULL);
    assert (test_number <= MAX_NUMBER_TEST - 1 && test_number >= 0);

    *(arg_storage -> result_data) = {NO_ROOTS, PRECISION_ZERO, NAN, NAN, NAN, NAN, NAN};

    (arg_storage -> result_data -> a) = (arg_storage -> ref_data[test_number].a);
    (arg_storage -> result_data -> b) = (arg_storage -> ref_data[test_number].b);
    (arg_storage -> result_data -> c) = (arg_storage -> ref_data[test_number].c);

    (arg_storage -> result_data -> nRoots) = EqSolver (arg_storage -> result_data);

    *test_state = TEST_FAILED;

    if (((arg_storage -> result_data -> nRoots) == (arg_storage -> ref_data[test_number].nRoots)))  {

        switch (arg_storage -> result_data -> nRoots) {
            case NO_ROOTS:
                *test_state = TEST_OK;
                break;

            case INFINITE_ROOTS:
                *test_state = TEST_OK;
                break;

            case ONE_ROOT:
                if (IsDoublesEqual ((arg_storage -> result_data -> x_1),
                    (arg_storage -> ref_data[test_number].x_1))) {

                    *test_state = TEST_OK;
                }
                break;

            case TWO_ROOTS:
                if (IsDoublesEqual ((arg_storage -> result_data -> x_1),
                    (arg_storage -> ref_data[test_number].x_1))) {

                    if (IsDoublesEqual ((arg_storage -> result_data -> x_2),
                        (arg_storage -> ref_data[test_number].x_2))) {

                        *test_state = TEST_OK;
                    }
                }
                break;

            default:
                fprintf (stderr, RED "Error has been occurred during solutions search.\n" NORMAL);
                assert (0);
        }
    }

    UnitTestOutput (arg_storage, test_number, *test_state);
}

void TestAll (UnitArgsStruct *const arg_storage, UnitTestConsts *const test_state) {

    assert (test_state != NULL);
    assert (arg_storage != NULL);
    assert ((arg_storage -> result_data) != NULL);
    assert ((arg_storage -> ref_data) != NULL);

    for (int test_number = 0; test_number < MAX_NUMBER_TEST; test_number++) {

        assert (test_number >= 0 && test_number < MAX_NUMBER_TEST);

        TestOne (arg_storage, test_number, test_state);

    /*     if (*test_state == TEST_FAILED) {
            break;
        } */
    }
}

