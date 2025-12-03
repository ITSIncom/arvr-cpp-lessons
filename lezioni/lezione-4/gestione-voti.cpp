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

/**
 * Aggiungere al programma a menù già scritto le seguenti funzionalità:
 *  - Possibilità di calcolare la media tra i valori inseriti.
 *    Tenere in considerazione solo i valori diversi da 0.
 *  - Aggiungere dei controlli più stringenti agli input dell'utente:
 *   - Gli indici devono essere sempre compresi tra 1 e 10.
 *     Se l'indice non è valido, visualizzare un messaggio di errore e
 *      permettere all'utente di inserire in nuovo indice.
 *   - I valori validi da inserire possono andare solo da 1 a 10
 *      (si tratta di voti scolastici).
 *  - Possibilità di inserire in maniera massiva tutti i valori mancanti.
 *    Scorrere tutto l'array e - laddove si trovi un valore a 0 - chiedere
 *     all'utente di inserire quel valore.
 *    Una volta terminata l'iterazione, si dovrebbero avere tutte e 10
 *     le celle valorizzate correttamente. 
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
    printf(" 5. Calcolare la media\n");
    printf(" 6. Inserire i valori mancanti\n");
    printf(" 9. Terminare il programma\n");
    printf("\n");
    printf("Selezionare quello che si desidera fare: ");
    scanf(" %c", &risposta);
    printf("\n");

    return risposta;
}
int chiedi_indice()
{
    int indice;

    printf("Seleziona la cella nella quale salvare il valore (1 <= x <= %d): ", LENGTH);
    scanf("%d", &indice);

    while ((indice < 1) || (indice > 10))
    {
        printf("\n");
        printf("Indice non valido. Riprova.\n");
        printf("Seleziona la cella nella quale salvare il valore (1 <= x <= %d): ", LENGTH);
        scanf("%d", &indice);
    }

    return indice;
}

void salva_valore(int index)
{
    int value;

    printf("Inserire il valore da salvare nella cella #%d: ", index);
    scanf("%d", &value);

    while ((value < 1) || (value > 10))
    {
        printf("\n");
        printf("Valore non valido. Dev'essere compreso tra 1 e 10. Riprova.\n");
        printf("Inserire il valore da salvare nella cella #%d: ", index);
        scanf("%d", &value);
    }

    values[index - 1] = value;
}
void visualizza_valore()
{
    int index = chiedi_indice();
    int value = values[index - 1];

    if (value != 0)
    {
        printf("La cella #%d contiene: %d\n", index, value);
    }
    else
    {
        printf("La cella #%d non contiene alcun valore.\n", index);
    }
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

int conta_valori()
{
    int conto = 0;
    for (int i = 0; i < LENGTH; i += 1)
    {
        if (values[i] != 0)
        {
            conto += 1;
        }
    }

    return conto;
}

int somma_array()
{
    int somma = 0;

    for (int i = 0; i < LENGTH; i += 1)
    {
        somma += values[i];
    }

    return somma;
}
float media_array()
{
    int sum = somma_array();
    int count = conta_valori();

    return (float)sum / count;
}

void inserisci_mancanti()
{
    int count = LENGTH - conta_valori();
    if (count == 0)
    {
        printf("Non ci sono valori mancanti da inserire.\n");

        return;
    }

    printf("Sono presenti %d valori mancanti.\n", count);

    for (int i = 0; i < LENGTH; i += 1)
    {
        if (values[i] == 0)
        {
            salva_valore(i + 1);
        }
    }
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
            int index = chiedi_indice();

            salva_valore(index);
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
            int result = somma_array();

            printf("La somma di tutti i valori inseriti è: %d\n", result);
        }
        else if (answer == '5')
        {
            float result = media_array();

            printf("La media di tutti i valori inseriti è: %f\n", result);
        }
        else if (answer == '6')
        {
            inserisci_mancanti();
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
