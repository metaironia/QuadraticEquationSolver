#ifndef UNIT_TEST_H_INCLUDED
#define UNIT_TEST_H_INCLUDED

#include "consts_for_quad.h"

/** \defgroup UnitTest Unit tests
    @{
*/

/**
    This enum contains numeric representation of unit test states.
*/
enum UnitTestConsts {
    TEST_STATE_NULL = -1,   ///< this state exists to classify output errors in unit tests
    TEST_FAILED,
    TEST_OK,

};

/// This is the number of unit tests.
const int MAX_NUMBER_TEST = 4;

/// This is the max length of string of user's answer when unit test was run.
const int STR_LEN = 2;

/// This number exists to classify input errors in unit tests.
const int TEST_NUMBER_NULL = -1;

/**
    This is the struct with arguments for function UnitTestMain().
*/
struct UnitArgsStruct {
    CoeffAndRoots *ref_data;
    CoeffAndRoots *result_data;
};

/** \defgroup UnitTestTest Testing functions
    @{
*/

/**
    Main function of the unit tests.
    @param [in, out] *storage the pointer to CoeffAndRoots struct of reference data and CoeffAndRoots struct of result data.
    @return 0 if unit test was run, -1 if unit test was not run
    @see UnitTestInput(), TestOne(), TestAll(), UnitTestOutput()
*/
int UnitTestMain (void *storage);

/**
    Function that run one unit test.
    @param [in, out] *storage the pointer to CoeffAndRoots struct of reference data and CoeffAndRoots struct of result data.
    @param [in] test_number the number of entered unit test.
    @param [in, out] *test_state the pointer to UnitTestConsts struct.
    @see TestAll()
*/
void TestOne (UnitArgsStruct *arg_storage, int test_number, UnitTestConsts *test_state);

/**
    Function that run all unit tests.
    @param [in, out] *storage the pointer to CoeffAndRoots struct of reference data and CoeffAndRoots struct of result data.
    @param [in] test_number the number of entered unit test.
    @param [in, out] *test_state the pointer to UnitTestConsts struct.
    @see TestOne()
*/
void TestAll (UnitArgsStruct *arg_storage, UnitTestConsts *test_state);
/**
    @}
*/


#endif
