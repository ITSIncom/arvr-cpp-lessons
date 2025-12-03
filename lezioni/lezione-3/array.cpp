#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Scrivere un programma che chieda all'utente
 *  5 valori in input e che li salvi all'interno di un array.
 * 
 * Stampare - successivamente - l'array una volta valorizzato.
 */

int main()
{
    int voti[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci il %do voto: ", i + 1);
        scanf("%d", &voti[i]);
    }

    printf("\n");

    /* per stampare l'array in ordine di caricamento */
    for (int i = 0; i < 5; i++)
    {
        printf("Il %do valore è: %d\n", i + 1, voti[i]);
    }

    /* per stampare l'array in ordine inverso */
    for (int i = 4; i >= 0; i--)
    {
        printf("Il %do valore è: %d\n", i + 1, voti[i]);
    }

    return 0;
}
