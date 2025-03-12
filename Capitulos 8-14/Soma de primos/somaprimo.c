#include <stdio.h>
#include <math.h>

int main() {
	int num1;
	int num2;
	int soma = 0;

	printf("Mim de um numero papai:\n");
	scanf("%d", &num1);
	printf("Otro numero:\n");
	scanf("%d", &num2);

	int maior;
	int menor;

	if(num1 > num2) {
		maior = num1;
		menor = num2;
	} else
		maior = num2;
		menor = num1;

	for(int i = menor; i <= maior; i++) {
		int qtddivisores = 0;
		
		for(int j = 2; j <= (int)sqrt(i); j++) {
			if(i % j == 0){
				qtddivisores++;
				break;
			}
		}
		if(qtddivisores == 0){
		soma = soma + i;
		}
	}
	printf("A soma dos primos entre %d e %d vale %d", menor, maior, soma);
}