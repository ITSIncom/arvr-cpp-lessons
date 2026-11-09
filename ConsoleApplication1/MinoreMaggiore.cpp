#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int minore_maggiore()
{
	int num1, num2, num3, num4, num5;

	printf("Inserisci il primo valore: ");
	scanf("%d", &num1);

	printf("Inserisci il secondo valore: ");
	scanf("%d", &num2);

	printf("Inserisci il terzo valore: ");
	scanf("%d", &num3);

	printf("Inserisci il quarto valore: ");
	scanf("%d", &num4);

	printf("Inserisci il quinto valore: ");
	scanf("%d", &num5);

	int minore = num1, maggiore = num1;

	if (num2 > maggiore)
	{
		maggiore = num2;
	}
	if (num3 > maggiore)
	{
		maggiore = num3;
	}
	if (num4 > maggiore)
	{
		maggiore = num4;
	}
	if (num5 > maggiore)
	{
		maggiore = num5;
	}

	printf("Il numero piu' grande e': %d\n", maggiore);

	if (num2 < minore)
	{
		minore = num2;
	}
	if (num3 < minore)
	{
		minore = num3;
	}
	if (num4 < minore)
	{
		minore = num4;
	}
	if (num5 < minore)
	{
		minore = num5;
	}

	printf("Il numero piu' piccolo e': %d\n", minore);

	int somma = num1 + num2 + num3 + num4 + num5;
	float media = (float)somma / 5;

	printf("La media dei numeri inseriti e': %.2f\n", media);

	return 0;
}
