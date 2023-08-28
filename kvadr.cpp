#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "consts_for_quad.h"
#include "solver_math_operation.h"
#include "vvod_vivod.h"
#include "unit_test.h"
#include "flag_checker.h"

extern AllFlags sFlagsForCmd;

struct CoeffAndRoots Quadr = {NO_ROOTS, PRECISION_ZERO, NAN, NAN, NAN, NAN, NAN};

int main (int argc, char *argv[]) {

    if (argc != FIRST_ARG) {

        FlagChecker (argv, argc, &sFlagsForCmd);
        return 0;
    }

    char otvet[STLEN] = {0};

    enum UserAnswer num_answer = YES;

    while (num_answer) {

        CoeffInput (&Quadr);

        assert (isfinite (Quadr.a));
        assert (isfinite (Quadr.c));
        assert (isfinite (Quadr.b));

        PrecisionInput (&Quadr);

        assert ((Quadr.precision) > PRECISION_ZERO &&
                (Quadr.precision) < PRECISION_MAX);

        Quadr.nRoots = EqSolver (&Quadr);

        assert (Quadr.nRoots <= INFINITE_ROOTS && Quadr.nRoots >= NO_ROOTS);

        EqOutput (&Quadr);

        num_answer = OtvetInput (otvet);

        assert (num_answer == YES || num_answer == NO);
    }

    printf ("Program was finished.");
    return 0;
}
