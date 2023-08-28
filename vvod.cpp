#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#include "consts_for_quad.h"
#include "vvod_vivod.h"

extern CoeffAndRoots Quadr;

void CoeffInput (struct CoeffAndRoots *EqMathCoeffs) {

    assert (EqMathCoeffs != NULL);

    printf ("Enter coefficients of the quadratic equation A, B and C:\n");

    enum Coeffs coeff_status = FIRST_COEFF;

    int vvod_status_cf = -1;

    while (((coeff_status = (Coeffs) (scanf ("%lf %lf %lf", &(EqMathCoeffs -> a),
           &(EqMathCoeffs -> b), &(EqMathCoeffs -> c)))) != THIRD_COEFF) ||
           (vvod_status_cf = VvodCheck())) {

    // спросить про enum + 1

        if (coeff_status == NO_COEFF) {
            coeff_status = FIRST_COEFF;
        }

        switch (coeff_status) {
            case FIRST_COEFF:
                fprintf (stderr, RED "First coefficient is incorrect! "
                                     "Enter the coefficients once again.\n" NORMAL);
                break;

            case SECOND_COEFF:
                fprintf (stderr, RED "Second coefficient is incorrect! "
                                     "Enter the coefficients once again.\n" NORMAL);
                break;

            case THIRD_COEFF:
                fprintf (stderr, RED "Third coefficient is incorrect! "
                                     "Enter the coefficients once again.\n" NORMAL);
                break;

            case NO_COEFF:
            default:
                fprintf (stderr, RED "Error occurred "
                                     "during input of the coefficient." NORMAL);
                assert(0);
        }

        VvodClear();
    }

    VvodClear();
}

void PrecisionInput (struct CoeffAndRoots *EqMathCoeffs) {

    assert (EqMathCoeffs != NULL);

    printf ("Enter the precision (number of digits after the decimal dot):\n");

    int vvod_status_pr = -1;

    while ((vvod_status_pr = (scanf ("%d", &(EqMathCoeffs -> precision)) != 1)) ||
           (vvod_status_pr = VvodCheck()) ||
           ((EqMathCoeffs -> precision) <= PRECISION_ZERO) ||
           ((EqMathCoeffs -> precision) >= PRECISION_MAX)) {

        if (vvod_status_pr) {
            fprintf (stderr, RED "Entered number of digits is incorrect! "
                                 "Enter the number of digits once again.\n" NORMAL);
        }
        else if ((EqMathCoeffs -> precision) >= PRECISION_MAX)
            fprintf (stderr, RED "Entered number of digits is too big! "
                                 "Enter the number of digits once again.\n" NORMAL);
        else
            fprintf (stderr, RED "Entered number of digits is incorrect! "
                                 "Enter the number of digits once again.\n" NORMAL);

        (EqMathCoeffs -> precision) = PRECISION_ZERO;

        VvodClear();
    }

    VvodClear();
}

enum UserAnswer OtvetInput (const char *otvet) {

    assert (otvet != NULL);

    for (int attempts = 0; attempts < MAX_ATTEMPTS; attempts++) {

        if ((otvet[0] = (char) (tolower (getchar()))) == QUIT_MARK &&
            !VvodCheck()) return NO;

        if (otvet[0] == ENTER) return YES;

        if (attempts != MAX_ATTEMPTS - 1)
            fprintf (stderr, RED "Enter correct input! "
                                 "Remaining attempts: %d\n" NORMAL,
                                  MAX_ATTEMPTS - attempts - 1);

        VvodClear();
    }
    return NO;
}

void VvodClear (void) {

    while (getchar() != ENTER)
        continue;
}


int VvodCheck (void) {

    char symbol = 0;


    while ((symbol = (char) getchar()) != ENTER) {

        if (symbol != SPACE)
            return 1;
    }

    ungetc (symbol, stdin);
    return 0;
}


