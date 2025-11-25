#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Scrivere una calcolatrice che permetta all'utente di
 *  eseguire molteplici operazioni (separate tra loro),
 *  restituisca il risultato corretto e chieda all'utente
 *  se vuole continuare a fare altri calcoli (S/N - Y/N).
 *
 * Quando l'utente specifica di non voler più continuare
 *  a fare calcoli, uscire dal programma.
 */

int main()
{
    int numero1;
    int numero2;

    char operatore;
    char risposta;

    float risultato;

    do
    {
        printf("Inserisci un numero: ");
        scanf("%d", &numero1);

        printf("Inserisci un altro numero: ");
        scanf("%d", &numero2);

        printf("Inserisci un operatore (`+`, `-`, `*`, `/`): ");
        scanf(" %c", &operatore);

        printf("\n");

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

        printf("%d %c %d = %f\n\n", numero1, operatore, numero2, risultato);

        printf("Si desidera continuare e eseguire un nuovo calcolo? (S/N) ");
        scanf(" %c", &risposta);

        printf("\n");
    }
    while ((risposta == 's') || (risposta == 'S'));

    return 0;
}
