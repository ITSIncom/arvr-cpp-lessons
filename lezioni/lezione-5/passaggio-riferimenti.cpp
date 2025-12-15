#pragma warning(disable:4996)
#include <stdio.h>

/**
 * Esempio di passaggio di riferimenti.
 */

void tocco_vampirico(int* vita_attaccante, int* vita_vittima, int danno)
{
    *vita_vittima -= danno;
    *vita_attaccante += (danno / 2);
}

int main()
{
    int player1_health = 30;
    int player2_health = 45;

    tocco_vampirico(&player1_health, &player2_health, 15);

    printf("La vita del giocatore 1 è: %d\n", player1_health); // 37
    printf("La vita del giocatore 2 è: %d\n", player2_health); // 30

    return 0;
}
