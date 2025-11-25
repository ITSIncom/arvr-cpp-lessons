#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Realizza una calcolatrice che chieda in input all'utente:
 *  - Un primo numero.
 *  - Un secondo numero.
 *  - Un operatore.
 * 
 * L'applicazione stamperà a video il risultato dell'operazione corretto.
 * 
 * Happy coding!
 */

int main()
{
    int numero1;
    int numero2;

    char operatore;

    printf("Inserisci un numero: ");
    scanf("%d", &numero1);

    printf("Inserisci un altro numero: ");
    scanf("%d", &numero2);

    printf("Inserisci un operatore (`+`, `-`, `*`, `/`): ");
    scanf(" %c", &operatore);

    printf("\n");

    float risultato;

    switch (operatore)
    {
        case '+':
            risultato = numero1 + numero2;
            break;

        case '-':
            risultato = numero1 - numero2;
            break;

        case '*':
            risultato = numero1 * numero2;
            break;

        case '/':
            if (numero2 == 0)
            {
                printf("Non puoi dividere per 0. Termino il programma.\n");
                return 2;
            }

            risultato = (float)numero1 / numero2;
            break;

        default:
            printf("L'operatore `%c` inserito non è valido. Termino il programma.\n", operatore);
            return 1;
    }

    printf("%d %c %d = %f\n", numero1, operatore, numero2, risultato);
    return 0;
}
