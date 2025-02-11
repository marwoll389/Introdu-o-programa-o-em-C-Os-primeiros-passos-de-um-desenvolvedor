#include <stdio.h> 

#define NUMERO_INICIAL 2
#define REPETICOES 25

//imprima todos os pares entre 2 e 50
int main() {

	int numero = NUMERO_INICIAL;

	for(int i = 1; i <= REPETICOES; i++) {
		
		if(numero % 2 >= 1) {
			i--;
		
		} else 
			printf("%d\n", numero);
			numero = numero + 1;
	}
}