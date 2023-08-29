#include <math.h>
#include <assert.h>
#include <stdio.h>

#include "consts_for_quad.h"
#include "solver_math_operation.h"

extern CoeffAndRoots Quadr;

enum RootsQuantity EqSolver (struct CoeffAndRoots *const EqMathCoeffs) {

    assert (EqMathCoeffs != NULL);

    assert (isfinite (EqMathCoeffs -> a));
    assert (isfinite (EqMathCoeffs -> b));
    assert (isfinite (EqMathCoeffs -> c));

    if (IsZero ((EqMathCoeffs -> a))) {

        return LinearSolve (EqMathCoeffs);

        assert (isfinite (EqMathCoeffs -> x_1));
    }

    double discr = (EqMathCoeffs -> b)*(EqMathCoeffs -> b) -
                 4*(EqMathCoeffs -> a)*(EqMathCoeffs -> c);

    if (IsDoubleBigger (discr, 0)) {

        double sqrt_discr = sqrt (discr);

        (EqMathCoeffs -> x_1) = (-(EqMathCoeffs -> b) - sqrt_discr) /
                                                         (2*(EqMathCoeffs -> a));

        (EqMathCoeffs -> x_2) = (-(EqMathCoeffs -> b) + sqrt_discr) /
                                                         (2*(EqMathCoeffs -> a));

        assert (isfinite (EqMathCoeffs -> x_1));
        assert (isfinite (EqMathCoeffs -> x_2));

        return TWO_ROOTS;
    }

    if (IsDoublesEqual (discr, 0)) {

        (EqMathCoeffs -> x_1) = (-(EqMathCoeffs -> b)) / (2*(EqMathCoeffs -> a));

        assert (isfinite (EqMathCoeffs -> x_1));

        return ONE_ROOT;
    }
        return NO_ROOTS;
}

enum RootsQuantity LinearSolve (struct CoeffAndRoots *const EqMathCoeffs) {

    assert (EqMathCoeffs != NULL);

    assert (isfinite (EqMathCoeffs -> b));
    assert (isfinite (EqMathCoeffs -> c));

    if (IsZero ((EqMathCoeffs -> b))) {

        return (IsZero ((EqMathCoeffs -> c)) ? INFINITE_ROOTS : NO_ROOTS);
    }

    (EqMathCoeffs -> x_1) = (-(EqMathCoeffs -> c)) / (EqMathCoeffs -> b);

    assert (isfinite (EqMathCoeffs -> x_1));

    return ONE_ROOT;
}
