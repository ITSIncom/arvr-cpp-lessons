#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

int main()
{
	int numero;

	printf("Inserisci un numero per verificare se sia primo: ");
	scanf("%d", &numero);

	if (numero < 2)
	{
		printf("Il numero %d non e' primo.", numero);
	}
	else if (numero == 2)
	{
		printf("Il numero %d e' primo.", numero);
	}
	else if ((numero % 2) == 0)
	{
		printf("Il numero %d non e' primo.", numero);
	}
	else
	{
		int divisore = 3;
		int limit = sqrt(numero);

		while (divisore <= limit)
		{
			if ((numero % divisore) == 0)
			{
				printf("Il numero %d non e' primo.", numero);

				return 0;
			}

			divisore = divisore + 2;
		}

		printf("Il numero %d e' primo.", numero);
	}
}
