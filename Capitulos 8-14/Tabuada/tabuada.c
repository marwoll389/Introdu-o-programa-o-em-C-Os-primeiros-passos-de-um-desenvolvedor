#include <stdio.h>
#include <stdlib.h>

int main() {
	int numero;

	printf("Mim de um numero papai\n");
	scanf("%d", &numero);

	FILE* f = fopen("tabuada.txt", "w+");

	if(f == NULL){
		printf("Deu merda");
		exit(1);
	}
	
	for(int i = 1; i <= 20; i++){
		int x = numero;
		x = x * i;
		fprintf(f, "%d\n", x);
	}
	fclose(f);
}