#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Chiedere all'utente di inserire due numeri.
 * Se i due numeri sono uguali, stampare a video un messaggio di conferma.
 * Se i due numeri sono diversi, stampare a video un altro messaggio.
 */

int main()
{
    int x;
    int y;

    printf("Inserisci il primo numero: ");
    scanf("%d", &x);

    printf("Inserisci il secondo numero: ");
    scanf("%d", &y);

    if (x == y)
    {
        printf("Bravo! Hai inserito 2 numeri uguali.");
    }
    else
    {
        printf("Bravo! Hai inserito 2 numeri diversi.");
    }

    return 0;
}
