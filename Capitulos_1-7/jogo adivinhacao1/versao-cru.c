#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	//contextualização
	printf("*************************\n");
	printf("Bem vindo ao jogo xesque!\n");
	printf("*************************\n");
	
	//declarando variaveis
	double pontos = 1000;	
	int dificuldade;
	int qtdtentativas;
	int acertou;		

	//randomizando o numero secreto
	srand(time(0));
	int numero = rand() % 100;

	//selecinando a dificuldade
	printf("Selecione sua o numero da sua dificuldade:\n");
	printf("1- Facil, 2- Medio, 3- Dificil\n");
	scanf("%d", &dificuldade);
	
	switch(dificuldade) {
		case 1:
			qtdtentativas = 20;
			break;
		case 2:
			qtdtentativas = 12;
			break;
		default: 
			qtdtentativas = 6;
			break;
	}
	
	//comparando resultados
	for( int i = 1; i <= qtdtentativas; i++) {
	
		int chute;
		acertou = chute == numero;
		
		printf("Chute um numero\n");
		scanf("%d", &chute);
		
		if(chute < 0) {
			printf("Apenas numaros positivos sao permitidos!\n");
			continue;
		}
		
		int menor = chute < numero;	

			if(acertou) {
			break;
			} else 
			if(menor) {
			printf("Seu chute eh menor que o numero secreto!\n");
		
			} else 
			printf("Seu chute eh maior que o numero secreto!\n");
 		
		printf("Tentativa %d de %d\n\n", i, qtdtentativas);
		pontos = pontos - abs(chute - numero) / 2.0;
	} 
	//Fim do jogo
	printf("Fim de jogo!\n");
	if(!acertou) {
		printf("Voce perdeu!Tente novamente!\n");
	} else {
		printf("Parabens, voce venceu!\n");
		printf("Sua pontuacao foi: %.2f", pontos);
	}
}