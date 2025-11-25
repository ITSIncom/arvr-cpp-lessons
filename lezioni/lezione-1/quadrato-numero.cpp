#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Scrivere un programma che chieda all'utente di inserire un
 *  numero e che ritorni quel numero alla seconda.
 */


int main()
{
    int numeroPreferito;

    printf("Inserisci il tuo numero preferito: ");
    scanf("%d", &numeroPreferito);

    printf("\n");

    int numeroAllaSeconda = numeroPreferito * numeroPreferito;

    printf("Il valore è: %d\n", numeroAllaSeconda);

    return 0;
}
