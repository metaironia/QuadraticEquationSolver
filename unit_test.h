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

/** \defgroup UnitTestTest Testing functions
    @{
*/

/**
    Main function of the unit tests.
    @param [in, out] EqMathCoeffs the pointer to CoeffAndRoots struct.
    @param [in] EqMathCoeffsRef the pointer to CoeffAndRoots struct with reference data.
    @return 0 if unit test was run, -1 if unit test was not run
    @see UnitTestInput(), TestOne(), TestAll(), UnitTestOutput()
*/
int UnitTestMain (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef);

/**
    Function that run one unit test.
    @param [in, out] *EqMathCoeffs the pointer to CoeffAndRoots struct.
    @param [in] *EqMathCoeffsRef the pointer to CoeffAndRoots struct with reference data.
    @param [in] test_number the number of entered unit test.
    @param [in, out] *test_state the pointer to UnitTestConsts struct.
    @see TestAll()
*/
void TestOne (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef,
              int test_number, UnitTestConsts *test_state);

/**
    Function that run all unit tests.
    @param [in, out] *EqMathCoeffs the pointer to CoeffAndRoots struct.
    @param [in] *EqMathCoeffsRef the pointer to CoeffAndRoots struct with reference data.
    @param [in] test_number the number of entered unit test.
    @param [in, out] *test_state the pointer to UnitTestConsts struct.
    @see TestOne()
*/
void TestAll (CoeffAndRoots *EqMathCoeffs, CoeffAndRoots *EqMathCoeffsRef,
              UnitTestConsts *test_state);
/**
    @}
*/


#endif
