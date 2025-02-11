#include <stdio.h>

int main() {
	
	int numero;
	printf("Escolha um numero\n");
	scanf("%d", &numero);
	printf(" \n\n");

	for(int i = 1; i <= 100; i++) {

		int resultado = numero * i;
		printf("%d X %d = %d\n", numero, i, resultado);
	}
}