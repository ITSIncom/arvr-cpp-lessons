#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int anno_bisestile()
{
	int anno = 1;

	while (anno > 0)
	{
		printf("Inserisci un anno per controllare che sia bisestile: ");
		scanf("%d", &anno);

		if (anno <= 0)
		{
			break;
		}
		if ((anno % 400 == 0) || ((anno % 100 != 0) && (anno % 4 == 0)))
		{
			printf("L'anno %d e' bisestile.\n", anno);
		}
		else
		{
			printf("L'anno %d non e' bisestile.\n", anno);
		}
	}

	printf("Grazie, arrivederci e torna presto.\n");

	return 0;
}
