#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int anno_bisestile()
{
	int anno;

	printf("Inserisci un anno per controllare che sia bisestile: ");
	scanf("%d", &anno);

	if ((anno % 400 == 0) || ((anno % 100 != 0) && (anno % 4 == 0)))
	{
		printf("L'anno %d e' bisestile.", anno);
	}
	else
	{
		printf("L'anno %d non e' bisestile.", anno);
	}

	return 0;
}
