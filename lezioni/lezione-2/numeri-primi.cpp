#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>

/**
 * Scrivere un programma che dato in input un numero chiesto
 * all'utente, dica se tale numero è un numero primo oppure no.
 * 
 * Cosa definisce un numero primo?
 * Un numero si dice "primo" se è divisibile solamente per
 *  1 e per se stesso.
 * 
 * Esempi di numeri primi sono:
 *  - 2
 *  - 3
 *  - 5
 *  - 23
 *  - 101
 * 
 * Happy coding!
 */

int main()
{
    bool isPrime;

    int value;
    int divisor;

    printf("Inserisci un numero per verificare se sia primo: ");
    scanf("%d", &value);

    printf("\n");

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

    if (value > 1)
    {
        if (isPrime == true)
        {
            printf("Il numero `%d` è un numero primo.\n", value);
        }
        else
        {
            printf("Il numero `%d` è divisibile per: %d\n", value, divisor);
            printf("Non è un numero primo.\n");
        }
    }
    else if (value < 0)
    {
        printf("Non sono considerati i numeri negativi. Usa il valore assoluto del numero.");
    }
    else if (value == 1)
    {
        printf("Il numero `1` non è un numero primo.");
    }
    else
    {
        printf("Il numero `0` non è un numero primo.");
    }

    return 0;
}
