#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Scrivere un programma che calcoli il numero di giorni presenti all'interno dei mesi.
 * Chiedere all'utente di inserire:
 *  - il numero del mese: 1 -> Gennaio, 2 -> Febbraio, ecc...
 *  - il numero dell'anno: 2020, 2024, 1970, ecc...
 * 
 * Restituire il numero di giorni presenti all'interno del mese scelto,
 *  stando attendi a verificare eventuali anni bisestili.
 * 
 * Cosa definisce un anno bisestile?
 * Se avete dei dubbi, cercate online.
 */

int main()
{
    int mese;
    int anno;

    int valore = 5 + (2 * 4);

    printf("Inserisci il numero del mese: ");
    scanf("%d", &mese);

    printf("Inserisci l'anno: ");
    scanf("%d", &anno);

    printf("\n");

    int giorniDelMese;

    switch (mese)
    {
        case 1: // Gennaio
        case 3: // Marzo
        case 5: // Maggio
        case 7: // Luglio
        case 8: // Agosto
        case 10: // Ottobre
        case 12: // Dicembre
            giorniDelMese = 31;

            break;

        case 4: // Aprile
        case 6: // Giugno
        case 9: // Settembre
        case 11: // Novembre
            giorniDelMese = 30;

            break;

        case 2: // Febbraio
            if ((anno % 4) != 0)
            {
                giorniDelMese = 28;
            }
            else if (((anno % 100) == 0) && ((anno % 400) == 0))
            {
                giorniDelMese = 29;
            }
            else
            {
                giorniDelMese = 28;
            }

            break;

        default:
            printf("Il mese `%d` inserito non è valido. Termino il programma.\n", mese);
            return 1;
    }

    printf("Il mese %d/%d presenta %d giorni.\n", mese, anno, giorniDelMese);
    return 0;
}
