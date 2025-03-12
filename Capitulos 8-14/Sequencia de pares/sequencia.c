#include <stdio.h>
#include <stdlib.h>

int main(){
	int num1;
	int num2;
	int soma = 0;

	printf("Mim de um numero:\n");
	scanf("%d", &num1);
	printf("Outro numero:\n");
	scanf("%d", &num2);

	int menor;
	int maior;
	if(num1 > num2) {
		maior = num1;
		menor = num2;
	} else
		maior = num2;
		menor = num1;

	for(int i = menor; i <= maior; i++) {
		if(i % 2 != 1){
			soma = soma + i;
		}
	}
	printf("A soma dos pares entre %d e %d vale %d", menor, maior, soma);
}