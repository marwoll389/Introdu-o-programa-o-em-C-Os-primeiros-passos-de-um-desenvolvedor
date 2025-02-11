#include <stdio.h>

int main(){

	printf("Bem vindo a fatoracao!\n");

	int numeroinicial;

	while(1) {	
		printf("Escolha um numero\n");
		scanf("%d", &numeroinicial);

		if(numeroinicial < 0) {
			printf("Nao ha fatorial para negativos, tente novamente\n");
			continue;
		}

		int numerofinal = numeroinicial;
		int numero = numeroinicial;

		if(numeroinicial <= 1) {
			printf("O fatorial de %d vale 1", numero);
			break;
		} else if(numeroinicial > 1) {
		
				for (int i = 1; i < numero; i++) {
	 
					numeroinicial = numeroinicial - 1;
					numerofinal = numerofinal * numeroinicial;
				
				}
			
			printf("O fatorial de %d e %d", numero,  numerofinal);
			break;
			}
	}
}