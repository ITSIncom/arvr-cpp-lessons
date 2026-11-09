#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int main()
{
	int a, b, c;

	printf("Inserisci il valore di A: ");
	scanf("%d", &a);

	printf("Inserisci il valore di B: ");
	scanf("%d", &b);

	printf("Inserisci il valore di C: ");
	scanf("%d", &c);

	//printf("Inserisci la formula dell'equazione (Ax^2 + Bx + C): ");
	//scanf("%dx^2 + %dx + %d", &a, &b, &c);
	
	printf("A: %d\n", a);
	printf("B: %d\n", b);
	printf("C: %d\n", c);

	return 0;
}