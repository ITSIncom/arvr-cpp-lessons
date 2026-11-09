#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int ordine_alfabetico()
{
	char char1, char2;

	printf("Inserisci il primo carattere: ");
	scanf("%c", &char1);

	printf("Inserisci il secondo carattere: ");
	scanf(" %c", &char2);

	if ((int)char1 < (int)char2)
	{
		printf("Il carattere \"%c\" e' piu' piccolo di \"%c\".\n", char1, char2);
	}
	else if ((int)char1 > (int)char2)
	{
		printf("Il carattere \"%c\" e' piu' grande di \"%c\".\n", char1, char2);
	}
	else
	{
		printf("I caratteri sono identici.\n");
	}

	return 0;
}
