#pragma warning(disable:4996)
#include <math.h>
#include <stdio.h>

/**
 * Scrivere un programma che simuli il comportamento di una manopola
 *  di una cassaforte.
 * I numeri validi che la ghiera presenta vanno a 0 a 99 (compresi).
 *
 * Chiedere all'utente di inserire il valore da aggiungere.
 *  - Se inserisce un valore positivo, ruotare la ghiera in senso antiorario (i numeri cresceranno).
 *  - Se inserisce un valoroe negativo, ruotare la ghiera in senso orario (i numeri diminiuranno).
 *  - Se inserisce zero, uscire dal programma.
 * 
 * La ghiera parte da 50.
 * 
 * Contare - inoltre - quante volte avviene l'overflow dei valori:
 *  - quante volte passa da 99 a 0.
 *  - quante volte passa da 0 a 99.
 */

#define MAX 100

int main()
{
    int input;

    int ghiera = 50;
    int count = 0;

    printf("La ghiera parte da: %d\n\n", ghiera);

    do
    {
        printf("Inserisci un valore: ");
        scanf("%d", &input);

        ghiera += input;

        int quoziente = ghiera / MAX;
        count += abs(quoziente);

        ghiera = ghiera % MAX;
        if (ghiera < 0)
        {
            count += 1;
            ghiera = MAX + ghiera;
        }

        printf("Il nuovo valore della ghiera è: %d\n\n", ghiera);
    }
    while (input != 0);

    printf("La ghiera ha eseguito l'overflow %d volte.\n", count);

    return 0;
}
