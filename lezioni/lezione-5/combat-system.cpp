#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/**
 * Implementare un semplice sistema di combattimento a turni tra due giocatori.
 * Liberissimi di creare, estendere e implementare il tutto come meglio credete!
 */

struct Dice
{
    int sides;
    int rolls;
};

struct Move
{
    char name[32];

    Dice hitDice;
    Dice damageDice;
};

struct Class
{
    char name[16];

    Move moves[4];
};

struct Player
{
    int health;
    
    Class gameClass;
};

Class create_warrior_class()
{
    Class warrior;

    snprintf(warrior.name, sizeof(warrior.name), "Warrior");

    snprintf(warrior.moves[0].name, sizeof(warrior.moves[0].name), "Slash");
    warrior.moves[0].hitDice.sides = 6;
    warrior.moves[0].hitDice.rolls = 1;
    warrior.moves[0].damageDice.sides = 8;
    warrior.moves[0].damageDice.rolls = 1;

    snprintf(warrior.moves[1].name, sizeof(warrior.moves[1].name), "Heavy Strike");
    warrior.moves[1].hitDice.sides = 8;
    warrior.moves[1].hitDice.rolls = 1;
    warrior.moves[1].damageDice.sides = 12;
    warrior.moves[1].damageDice.rolls = 1;

    snprintf(warrior.moves[2].name, sizeof(warrior.moves[2].name), "Defensive Stance");
    warrior.moves[2].hitDice.sides = 4;
    warrior.moves[2].hitDice.rolls = 1;
    warrior.moves[2].damageDice.sides = 0;
    warrior.moves[2].damageDice.rolls = 0;

    snprintf(warrior.moves[3].name, sizeof(warrior.moves[3].name), "Berserk");
    warrior.moves[3].hitDice.sides = 10;
    warrior.moves[3].hitDice.rolls = 1;
    warrior.moves[3].damageDice.sides = 15;
    warrior.moves[3].damageDice.rolls = 1;

    return warrior;
}
Class create_mage_class()
{
    Class mage;

    snprintf(mage.name, sizeof(mage.name), "Mage");

    snprintf(mage.moves[0].name, sizeof(mage.moves[0].name), "Fireball");
    mage.moves[0].hitDice.sides = 6;
    mage.moves[0].hitDice.rolls = 1;
    mage.moves[0].damageDice.sides = 10;
    mage.moves[0].damageDice.rolls = 1;

    snprintf(mage.moves[1].name, sizeof(mage.moves[1].name), "Ice Spike");
    mage.moves[1].hitDice.sides = 8;
    mage.moves[1].hitDice.rolls = 1;
    mage.moves[1].damageDice.sides = 8;
    mage.moves[1].damageDice.rolls = 1;

    snprintf(mage.moves[2].name, sizeof(mage.moves[2].name), "Arcane Shield");
    mage.moves[2].hitDice.sides = 4;
    mage.moves[2].hitDice.rolls = 1;
    mage.moves[2].damageDice.sides = 0;
    mage.moves[2].damageDice.rolls = 0;

    snprintf(mage.moves[3].name, sizeof(mage.moves[3].name), "Lightning Bolt");
    mage.moves[3].hitDice.sides = 10;
    mage.moves[3].hitDice.rolls = 1;
    mage.moves[3].damageDice.sides = 12;
    mage.moves[3].damageDice.rolls = 1;

    return mage;
}
Class create_rogue_class()
{
    Class rogue;

    snprintf(rogue.name, sizeof(rogue.name), "Rogue");

    snprintf(rogue.moves[0].name, sizeof(rogue.moves[0].name), "Backstab");
    rogue.moves[0].hitDice.sides = 6;
    rogue.moves[0].hitDice.rolls = 1;
    rogue.moves[0].damageDice.sides = 8;
    rogue.moves[0].damageDice.rolls = 1;

    snprintf(rogue.moves[1].name, sizeof(rogue.moves[1].name), "Poison Dart");
    rogue.moves[1].hitDice.sides = 8;
    rogue.moves[1].hitDice.rolls = 1;
    rogue.moves[1].damageDice.sides = 6;
    rogue.moves[1].damageDice.rolls = 1;

    snprintf(rogue.moves[2].name, sizeof(rogue.moves[2].name), "Evasion");
    rogue.moves[2].hitDice.sides = 4;
    rogue.moves[2].hitDice.rolls = 1;
    rogue.moves[2].damageDice.sides = 0;
    rogue.moves[2].damageDice.rolls = 0;

    snprintf(rogue.moves[3].name, sizeof(rogue.moves[3].name), "Shadow Strike");
    rogue.moves[3].hitDice.sides = 10;
    rogue.moves[3].hitDice.rolls = 1;
    rogue.moves[3].damageDice.sides = 10;
    rogue.moves[3].damageDice.rolls = 1;

    return rogue;
}
Class create_cleric_class()
{
    Class cleric;

    snprintf(cleric.name, sizeof(cleric.name), "Cleric");

    snprintf(cleric.moves[0].name, sizeof(cleric.moves[0].name), "Smite");
    cleric.moves[0].hitDice.sides = 6;
    cleric.moves[0].hitDice.rolls = 1;
    cleric.moves[0].damageDice.sides = 8;
    cleric.moves[0].damageDice.rolls = 1;

    snprintf(cleric.moves[1].name, sizeof(cleric.moves[1].name), "Holy Light");
    cleric.moves[1].hitDice.sides = 8;
    cleric.moves[1].hitDice.rolls = 1;
    cleric.moves[1].damageDice.sides = 6;
    cleric.moves[1].damageDice.rolls = 1;

    snprintf(cleric.moves[2].name, sizeof(cleric.moves[2].name), "Divine Shield");
    cleric.moves[2].hitDice.sides = 4;
    cleric.moves[2].hitDice.rolls = 1;
    cleric.moves[2].damageDice.sides = 0;
    cleric.moves[2].damageDice.rolls = 0;

    snprintf(cleric.moves[3].name, sizeof(cleric.moves[3].name), "Judgment");
    cleric.moves[3].hitDice.sides = 10;
    cleric.moves[3].hitDice.rolls = 1;
    cleric.moves[3].damageDice.sides = 12;
    cleric.moves[3].damageDice.rolls = 1;

    return cleric;
}

Class random_class()
{
    int random_value = rand() % 4;
    switch (random_value)
    {
        case 0:
            return create_warrior_class();

        case 1:
            return create_mage_class();

        case 2:
            return create_rogue_class();

        case 3:
            return create_cleric_class();
    }
}
Class select_class()
{
    printf("Seleziona la tua classe:\n");
    printf(" 1. Warrior\n");
    printf(" 2. Mage\n");
    printf(" 3. Rogue\n");
    printf(" 4. Cleric\n");
    printf("\n");

    do
    {
        int choice;

        printf("Inserisci il numero corrispondente alla classe scelta: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
            case 1:
                return create_warrior_class();

            case 2:
                return create_mage_class();

            case 3:
                return create_rogue_class();

            case 4:
                return create_cleric_class();
        }

        printf("Scelta non valida.\n");
    }
    while (true);
}

void init_player(Player* player, Class gameClass)
{
    player -> health = 100;
    player -> gameClass = gameClass;
}

Move random_move(Player* player)
{
    int random_value = rand() % 4;

    return player -> gameClass.moves[random_value];
}
Move select_move(Player* player)
{
    printf("Seleziona la tua mossa:\n");

    for (int i = 0; i < 4; i++)
    {
        printf(" %d. %s\n", i + 1, player -> gameClass.moves[i].name);
    }

    printf("\n");

    do
    {
        int choice;

        printf("Inserisci il numero corrispondente alla mossa scelta: ");
        scanf("%d", &choice);

        printf("\n");

        if ((choice >= 1) && (choice <= 4))
        {
            return player -> gameClass.moves[choice - 1];
        }

        printf("Scelta non valida.\n");
    }
    while (true);
}

int compute_dice(Dice dice)
{
    int total = 0;

    for (int i = 0; i < dice.rolls; i++)
    {
        total += (rand() % dice.sides) + 1;
    }

    return total;
}

void play_turn(Player* attacker, Move move, Player* defender)
{
    printf("%s usa %s!\n", attacker -> gameClass.name, move.name);

    int hit_roll = compute_dice(move.hitDice);
    if (hit_roll >= 4)
    {
        int damage = compute_dice(move.damageDice);

        defender -> health -= damage;

        printf("Colpisce per %d danni!\n", damage);
        printf("La vita del difensore è ora: %d\n", defender -> health);

        if (defender -> health <= 0)
        {
            printf("%s è stato sconfitto! %s vince!\n", defender -> gameClass.name, attacker -> gameClass.name);

            exit(0);
        }
    }
    else
    {
        printf("L'attacco fallisce!\n");
    }
}

int main()
{
    Player player1;
    Player player2;

    init_player(&player1, select_class());
    init_player(&player2, random_class());

    int turn = rand() % 2;

    do
    {
        Move move;

        switch (turn)
        {
            case 0:
                printf("Turno del giocatore 1...\n");

                move = select_move(&player1);
                play_turn(&player1, move, &player2);

                break;

            case 1:
                printf("Turno del giocatore 2...\n");

                move = random_move(&player2);
                play_turn(&player2, move, &player1);

                break;
        }

        turn = (turn + 1) % 2;

        printf("\n");
    }
    while (true);

    return 0;
}
