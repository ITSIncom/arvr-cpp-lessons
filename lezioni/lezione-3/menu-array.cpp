#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Scrivere un programma che - all'avvio - inizializzi un vettore da
 *  10 elementi a `0`.
 *
 * Tramite un menù, permettere all'utente di selezionare le seguenti
 *  opzioni:
 *   - Salvare un valore all'interno dell'array.  
 *     Chiedere all'utente la cella nel quale inserire il nuovo valore.
 *   - Visualizzare una cella specifica all'iterno dell'array.
 *     Chiedere all'utente quale cella desidera visualizzare.
 *   - Stampare tutto l'array, visualizzando tutte le celle
 *      con valori diversi da 0 nel seguente formato:
 *       - Cella #1: 13
 *       - Cella #7: 23
 *       - Cella #9: -999
 *     Non stampare e ignorare le celle con valori a 0.
 *   - Eseguire e visualizzare la somma di tutti i valori
 *      presenti all'interno dell'array.
 *   - Uscire dal programma.
 */

#define LENGTH 10

int values[LENGTH];

char chiedi_menu()
{
    char risposta;

    printf("Opzioni disponibili:\n");
    printf(" 1. Salvare un valore\n");
    printf(" 2. Visualizzare un valore\n");
    printf(" 3. Visualizzare tutti i valori\n");
    printf(" 4. Eseguire la somma\n");
    printf(" 9. Terminare il programma\n");
    printf("\n");
    printf("Selezionare quello che si desidera fare: ");
    scanf(" %c", &risposta);
    printf("\n");

    return risposta;
}

void salva_valore()
{
    int index;

    printf("Seleziona la cella nella quale salvare il valore (1 <= x <= %d): ", LENGTH);
    scanf("%d", &index);

    printf("Inserire il valore da salvare nella cella #%d: ", index);
    scanf("%d", &values[index - 1]);
}
void visualizza_valore()
{
    int index;

    printf("Seleziona la cella di cui visualizzare il valore (1 <= x <= %d): ", LENGTH);
    scanf("%d", &index);

    printf("La cella #%d contiene: %d\n", index, values[index - 1]);
}
void stampa_array()
{
    printf("Tutti i valori:\n");

    for (int i = 0; i < LENGTH; i += 1)
    {
        if (values[i] != 0)
        {
            printf(" - Cella #%d: %d\n", (i + 1), values[i]);
        }
    }
}
void somma_array()
{
    int somma = 0;

    for (int i = 0; i < LENGTH; i += 1)
    {
        somma += values[i];
    }

    printf("La somma di tutti i valori inseriti è: %d\n", somma);
}

int main()
{
    char answer;

    for (int i = 0; i < LENGTH; i += 1)
    {
        values[i] = 0;
    }

    do
    {
        answer = chiedi_menu();

        if (answer == '1')
        {
            salva_valore();
        }
        else if (answer == '2')
        {
            visualizza_valore();
        }
        else if (answer == '3')
        {
            stampa_array();
        }
        else if (answer == '4')
        {
            somma_array();
        }
        else if (answer != '9')
        {
            printf("Scelta non valida. Riprova.\n");
        }

        printf("\n");
    }
    while (answer != '9');

    return 0;
}
