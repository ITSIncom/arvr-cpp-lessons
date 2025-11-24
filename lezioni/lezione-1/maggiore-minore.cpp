#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Scrivere un programma che chieda all'utente 2 valori `x` e `y`,
 *  stampi a video il nome della variabile più grande
 *  con il rispettivo valore.
 */

int main()
{
    int x;
    int y;

    printf("Inserisci il valore di X: ");
    scanf("%d", &x);

    printf("Inserisci il valore di Y: ");
    scanf("%d", &y);

    if (x > y)
    {
        printf("X è la variabile più grande. Il suo valore è: %d", x);
    }
    else if (y > x)
    {
        printf("Y è la variabile più grande. Il suo valore è: %d", y);
    }
    else
    {
        printf("X e Y presentano lo stesso valore. Il loro valore è: %d", x);
    }

    return 0;
}
