#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Realizza un programma che chieda all'utente 5 voti.
 * Per ogni voto, controllare che sia
 *  effettivamente una valutazione valida (1 <= x <= 10).
 * Se l'utente inserisce tutte votazioni valide,
 *  calcolare la media dei voti e stamparla a video.
 */

int main()
{
    int voto;
    int somma = 0;

    printf("Inserisci il primo voto: ");
    scanf("%d", &voto);

    if ((voto < 1) || (voto > 10))
    {
        printf("\nIl voto `%d` inserito non è un voto valido. Termino il programma.", voto);
        return 1;
    }

    somma += voto;

    printf("Inserisci il secondo voto: ");
    scanf("%d", &voto);

    if ((voto < 1) || (voto > 10))
    {
        printf("\nIl voto `%d` inserito non è un voto valido. Termino il programma.", voto);
        return 2;
    }

    somma += voto;

    printf("Inserisci il terzo voto: ");
    scanf("%d", &voto);

    if ((voto < 1) || (voto > 10))
    {
        printf("\nIl voto `%d` inserito non è un voto valido. Termino il programma.", voto);
        return 3;
    }

    somma += voto;

    printf("Inserisci il quarto voto: ");
    scanf("%d", &voto);

    if ((voto < 1) || (voto > 10))
    {
        printf("\nIl voto `%d` inserito non è un voto valido. Termino il programma.", voto);
        return 4;
    }
    somma += voto;

    printf("Inserisci il quinto voto: ");
    scanf("%d", &voto);

    if ((voto < 1) || (voto > 10))
    {
        printf("\nIl voto `%d` inserito non è un voto valido. Termino il programma.", voto);
        return 5;
    }

    somma += voto;

    printf("\nLa media dei voti inseriti è: %f", ((float)somma / 5));

    return 0;
}
