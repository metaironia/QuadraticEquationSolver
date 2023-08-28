#include <math.h>
#include <assert.h>

#include "consts_for_quad.h"
#include "solver_math_operation.h"

int IsZero (const double number) {

    assert (isfinite (number));

    return (fabs (number) < EPS);
}

double Maximum (const double number_1, const double number_2) {

    assert (isfinite (number_1));
    assert (isfinite (number_2));

    return ((number_1 > number_2) ? number_1 : number_2);
}

double Minimum (const double number_1, const double number_2) {

    assert (isfinite (number_1));
    assert (isfinite (number_2));

    return ((number_1 > number_2) ? number_2 : number_1);
}

int IsDoublesEqual (const double number_1, const double number_2) {

    assert (isfinite (number_1));
    assert (isfinite (number_2));

    return (fabs (number_1 - number_2) < EPS);
}

int IsDoubleBigger (const double number_1, const double number_2) {

    assert (isfinite (number_1));
    assert (isfinite (number_2));

    return ((number_1 - number_2) > EPS);
}
