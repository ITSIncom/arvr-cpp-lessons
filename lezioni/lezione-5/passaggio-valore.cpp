#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Scrivere una funzione per eseguire l'elevamento a potenza.
 * Avrà 2 numeri in input:
 *  - la base
 *  - l'esponente
 *
 * Non riusare la funzione `pow` di <math.h>!
 */

int potenza(int base, int esponente)
{
    int risultato = 1;

    for (int i = 0; i < esponente; i++)
    {
        risultato *= base;
    }

    return risultato;
}

int main()
{
    int base;
    int esponente;

    printf("Inserire la base: %d");
    scanf("%d", &base);
    printf("Inserire l'esponente: %d");
    scanf("%d", &esponente);

    printf("\n");

    int risultato = potenza(base, esponente);

    printf("Il risultato dell'elevamento a potenza è: %d\n", risultato);

    return 0;
}
