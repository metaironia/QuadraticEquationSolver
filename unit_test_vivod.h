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
    @param [in, out] *storage the pointer to CoeffAndRoots struct of reference data and CoeffAndRoots struct of result data.
    @param [in] test_number a number of test that user's run.
    @param [in, out] *test_state the pointer to UnitTestConsts struct.
*/
void UnitTestOutput (UnitArgsStruct *arg_storage, int test_number, UnitTestConsts *test_state);

/**
    @}
*/

#endif

