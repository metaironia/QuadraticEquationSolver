#ifndef UNIT_TEST_VVOD_H_INCLUDED
#define UNIT_TEST_VVOD_H_INCLUDED

/**
    \defgroup UnitTestInput Input
    \ingroup UnitTest
    @{
*/

/// This is mark for run all unit tests.
const int ALL_TESTS_MARK = 'a';

/**
    Function that reads user's answer when UnitTestMain() was run.
    @param [in, out] test_number a number of test that user's want to run.
    @param [in, out] user_input an array to read user's answer into.
    @note number of test will be written into \p test_number if user's answer is a number,
          else user's answer will be written to a \p user_input.
    @return 1 if input was successful, 0 if not.
*/
int UnitTestInput (int *test_number, char *user_input);

/**
    @}
*/

#endif
