#include <stdio.h>

int main() {

	int loop = 1;	
	while(loop == 1) {

	int a;
	int b;
	int operacao;

	printf("Qual operacao voce quer fazer?\n");
	printf("1 - Adicao, 2 - Subtracao, 3 - Multiplicacao, 4 - Divisao\n");
	scanf("%d", &operacao);

	printf("Quais o primeiro numero? ");
	scanf("%d", &a);
	printf("Qual o segundo numero? ");
	scanf("%d", &b);

	if(operacao == 1) {
		int adicao = a + b;
		printf("%d + %d = %d\n\n", a, b, adicao);
	} else if(operacao == 2){
			int subtracao = a - b;
			printf("%d - %d = %d\n\n", a, b, subtracao);
	} else if(operacao == 3) {
			int multiplicacao = a * b;
			printf("%d X %d = %d\n\n", a, b, multiplicacao);
	} else if(operacao == 4) {
		double divisao = (double)a / (double)b;
		printf("%d / %d = %.3f\n\n", a, b, divisao);
	}
	
		printf("Quer realizar mais uma operacao? Digite 1 se sim\n");
		scanf("%d", &loop);
	}
}