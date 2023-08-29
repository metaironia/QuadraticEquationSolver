#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#include "consts_for_quad.h"
#include "vvod_vivod.h"

extern CoeffAndRoots Quadr;

void CoeffInput (struct CoeffAndRoots *const EqMathCoeffs) {

    assert (EqMathCoeffs != NULL);

    printf ("Enter coefficients of the quadratic equation A, B and C separated by ENTER:\n");

    enum Coeffs coeff_status = NO_COEFF;

    double temp_for_coeff[3] = {NAN, NAN, NAN};

    while (coeff_status != COEFFS_OK) {

        coeff_status = NO_COEFF;

        for (int coeff_counter = 0; coeff_counter < COEFF_NUM; coeff_counter++) {

            assert (0 <= coeff_counter && coeff_counter < COEFF_NUM);

            if (scanf ("%lf", &temp_for_coeff[coeff_counter]) != 1 || VvodCheck()) {

                coeff_status = (Coeffs) (coeff_counter + 1);
                break;
            }
            else // можно ли написать просто без if?
                coeff_status = COEFFS_OK;
        }

        const char* which_coeff = NULL;

        switch (coeff_status) {
            case FIRST_COEFF_ERR:  which_coeff = "First";  break;
            case SECOND_COEFF_ERR: which_coeff = "Second"; break;
            case THIRD_COEFF_ERR:  which_coeff = "Third";  break;

            case COEFFS_OK: break;
            case NO_COEFF:

            default:
                fprintf (stderr, RED "Error occurred "
                                     "during input of the coefficient." NORMAL);
                assert(0);
        }

        if (coeff_status == COEFFS_OK) {

            EqMathCoeffs -> a = temp_for_coeff[0];
            EqMathCoeffs -> b = temp_for_coeff[1];
            EqMathCoeffs -> c = temp_for_coeff[2];

        } else
              fprintf (stderr, RED "%s coefficient is incorrect! "
                                   "Enter the coefficients once again.\n" NORMAL, which_coeff);
        VvodClear();
    }
}

void PrecisionInput (struct CoeffAndRoots *const EqMathCoeffs) {

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

enum UserAnswer OtvetInput (char *const otvet) {

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

        if (symbol != SPACE) {

            ungetc (symbol, stdin);
            return 1;
        }
    }

    ungetc (symbol, stdin);
    return 0;
}


