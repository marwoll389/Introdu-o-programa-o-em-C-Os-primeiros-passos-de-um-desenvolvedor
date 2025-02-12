#include <stdio.h> 

int main() {

	int numero1;
	int numero2;
	int numero3;
	printf("Escolha tres numeros:\n");
	scanf("%d", &numero1);
	scanf("%d", &numero2);
	scanf("%d", &numero3);

	if(numero1 > numero2 && numero2 > numero3) {
		printf("%d > %d > %d", numero1, numero2, numero3);
	}
	if(numero1 > numero3 && numero3 > numero2) {	
		printf("%d > %d > %d", numero1, numero3, numero2);
	}
	if(numero2 > numero1 && numero1 > numero3) {
		printf("%d > %d > %d", numero2, numero1, numero3);
	}
	if(numero2 > numero3 && numero3 > numero1) {	
		printf("%d > %d > %d", numero2, numero3, numero1);
	} 
	if(numero3 > numero1 && numero1 > numero2) {
		printf("%d > %d > %d", numero3, numero1, numero2);
	} 
	else 
		printf("%d > %d > %d", numero3, numero2, numero1);
	
	
}