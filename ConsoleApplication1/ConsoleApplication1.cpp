#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int main() // Questa è la funzione principale.
{
	printf("Ciao, Mondo!\n");
	printf("Questo e' il mio primo programma.\n");

	int valore1;
	int valore2;

	char operatore;

	printf("Inserisci il primo valore: ");
	scanf("%d", &valore1);

	printf("Inserisci il secondo valore: ");
	scanf("%d", &valore2);

	printf("Inserisci il simbolo dell'operazione da eseguire: ");
	scanf(" %c", &operatore);

	bool valido = true;
	int risultato;

	if (operatore == '+')
	{
		risultato = valore1 + valore2;
	}
	else if (operatore == '-')
	{
		risultato = valore1 - valore2;
	}
	else if ((operatore == '*') || (operatore == 'x'))
	{
		risultato = valore1 * valore2;
	}
	else if ((operatore == '/') || (operatore == ':'))
	{
		if (valore2 == 0)
		{
			valido = false;

			printf("Non e' possibile dividere per 0.\n");
		}
		else
		{
			risultato = valore1 / valore2;
		}
	}
	else
	{
		valido = false;

		printf("Il simbolo che hai inserito non e' valido.\n");
	}

	if (valido)
	{
		printf("Il risultato di %d %c %d = %d\n", valore1, operatore, valore2, risultato);
	}
}
