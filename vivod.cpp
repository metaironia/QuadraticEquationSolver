#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "consts_for_quad.h"
#include "solver_math_operation.h"
#include "vvod_vivod.h"

extern CoeffAndRoots Quadr;

void EqOutput (struct CoeffAndRoots *const EqMathCoeffs) {

    assert (EqMathCoeffs != NULL);

    switch (EqMathCoeffs -> nRoots) {
        case NO_ROOTS:
            printf ("This equation has no solution.\n");
            break;

        case ONE_ROOT:
            printf ("Solution of the equation : %.*f.\n", (EqMathCoeffs -> precision),
                                                          (EqMathCoeffs -> x_1));
            break;

        case TWO_ROOTS:
            printf ("Solution of the equation in ascending order: %.*f è %.*f.\n",
                    (EqMathCoeffs -> precision),
                    Minimum((EqMathCoeffs -> x_1), (EqMathCoeffs -> x_2)),
                    (EqMathCoeffs -> precision),
                    Maximum((EqMathCoeffs -> x_1), (EqMathCoeffs -> x_2)));
            break;

        case INFINITE_ROOTS:
            printf ("This equation has infinite number of the solutions.\n");
            break;

        default:
            fprintf (stderr, RED "Error has been occurred during solutions search.\n" NORMAL);

            assert(0);
    }

    printf ("\n" YELLOW "Press ENTER "
            "to find solutions of another quadratic equation,\n"
            "or enter \"q\" to exit the program.\n" NORMAL);
}
