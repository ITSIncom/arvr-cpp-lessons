#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>

/**
 * Scrivere un programma che chieda in input all'utente il numero
 * da cui iniziar a generare numeri primi.
 * Chiedere - inoltre - quanti numeri primi si vuole generare.
 * 
 * Stampare a video N numeri primi, secondo la richiesta dell'utente.
 */

int main()
{
    bool isPrime;

    int value;
    int divisor;

    int max;
    int count = 0;

    printf("Inserisci il numero da cui iniziare a generare numeri primi: ");
    scanf("%d", &value);

    printf("Inserisci quanti numeri primi vuoi generare: ");
    scanf("%d", &max);

    printf("\n");

    do
    {
        if ((value % 2) == 0)
        {
            isPrime = (value == 2);
            divisor = 2;
        }
        else
        {
            isPrime = true;
            divisor = 3;

            int limit = sqrt(value);

            do
            {
                if ((value % divisor) == 0)
                {
                    isPrime = (value == 3);
                }
                else
                {
                    divisor += 2;
                }
            }
            while ((isPrime) && (divisor <= limit));
        }

        if ((value > 1) && (isPrime == true))
        {
            printf("Numero primo trovato: %d\n", value);

            count += 1;
        }

        value += 1;
    }
    while (count < max);

    return 0;
}
