#include <stdio.h>
#include <math.h>

int main() {
	int numero;
	int hadivisores = 0;

	printf("Mim de um numero papai:\n");
	scanf("%d", &numero);

	if(numero == 1){
			printf("O numero nao e primo");
			return 0;
		}

	for(int i = 2; i <= (int)sqrt(numero); i++){

		if(numero % i == 0) {
			hadivisores = 1;
			break;
		}
	}
	if(hadivisores) {
		printf("O numero nao e primo");
	} else
		printf("O numero e primo");
}