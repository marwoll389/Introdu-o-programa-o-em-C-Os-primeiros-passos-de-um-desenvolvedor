#include <stdio.h>

int main() {

	int a;
	int b;
	

	printf("Escolha um numero: ");
	scanf("%d", &a);
	printf("Agora o numero que seja seu expoente: ");
	scanf("%d", &b);

	int valorfinal = a;

	for(int i = 1; i < b; i++) {
		valorfinal = valorfinal * a;
	}
	printf("%d elevado a %d e igual a %d", a, b, valorfinal);
}