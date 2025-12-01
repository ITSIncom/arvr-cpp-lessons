#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>

/**
 * Scrivere un programma che chieda all'utente un numero
 *  e che ne calcoli il risultato fattoriale.
 * 
 * es.
 *  2! = 1 * 2
 *  3! = 1 * 2 * 3
 *  5! = 1 * 2 * 3 * 4 * 5
 *  7! = 1 * 2 * 3 * 4 * 5 * 6 * 7
 */

int main()
{
    int value;

    int multiplier = 1;
    unsigned long result = 1;

    printf("Di che numero vuoi calcolare il fattoriale? ");
    scanf("%d", &value);

    while (multiplier <= value)
    {
        result *= multiplier;
        multiplier += 1;
    }

    printf("Il fattoriale di %d è: %lu", value, result);

    return 0;
}
