#ifndef UNIT_TEST_VIVOD_H_INCLUDED
#define UNIT_TEST_VIVOD_H_INCLUDED

#include "unit_test.h"
#include "consts_for_quad.h"

/**
    \defgroup UnitTestOutput Output
    \ingroup UnitTest
    @{
*/

/**
    Function that outputs results of unit tests.
    @param [in, out] *EqMathCoeffs the pointer to CoeffAndRoots struct.
    @param [in] *EqMathCoeffsRef the pointer to CoeffAndRoots struct with reference data.
    @param [in] test_number a number of test that user's run.
    @param [in, out] *test_state the pointer to UnitTestConsts struct.
*/
void UnitTestOutput (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef,
                     int test_number, UnitTestConsts *test_state);

/**
    @}
*/

#endif

