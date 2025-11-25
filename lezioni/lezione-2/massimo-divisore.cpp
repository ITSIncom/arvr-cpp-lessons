#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>

/**
 * Scrivere un programma che dato in input un numero
 *  chiesto all'utente, restituisca il suo più grande
 *  divisore.
 * 
 * Si noti che:
 *  - Se stesso è escluso.
 *  - Il divisore più grande può essere il numero 1.
 */

int main()
{
    int value;
    int divisor;

    printf("Inserisci un numero: ");
    scanf("%d", &value);

    printf("\n");

    divisor = value / 2;

    if ((value % 2) != 0)
    {
        bool found = false;

        do
        {
            if ((value % divisor) == 0)
            {
                found = true;
            }
            else
            {
                divisor -= 1;
            }
        }
        while ((found == false) && (divisor > 1));
    }

    printf("Il massimo divisore del numero `%d` è: %d\n", value, divisor);

    return 0;
}
