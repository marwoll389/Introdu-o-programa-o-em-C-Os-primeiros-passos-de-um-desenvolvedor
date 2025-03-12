#include <stdio.h>
#include <string.h>

int main () {

	int qtdnumeros = 0;
	printf("Vamos trabalhar com quantos numeros?\n");
	scanf("%d", &qtdnumeros);

	int numeros[qtdnumeros];

	for(int i = 0; i < qtdnumeros; i ++) {
		printf("\nEscolha um numero: ");
		scanf("%d", &numeros[i]);
	}
	int soma = 0;

	for(int j = 0; j < qtdnumeros; j++){
		soma = soma + numeros[j];		
	}
	printf("A soma dos numeros dados vale: %d", soma);
}