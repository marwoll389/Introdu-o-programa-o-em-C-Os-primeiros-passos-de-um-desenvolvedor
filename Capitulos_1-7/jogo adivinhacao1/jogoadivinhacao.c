#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PONTOS_INICIAIS 1000
#define QTD_TENTATIVAS_FACIL 15
#define QTD_TENTATIVAS_MEDIO 10
#define QTD_TENTATIVAS_DIFICIL 7

int jogardnv = 1;

int main() {
	do {
		//contextualização
		printf("********************************\n");
		printf("Bem vindo ao jogo adivinhesque!\n");
		printf("********************************\n\n");
		
		//declarando variaveis
		int acertou;
		int pontos = PONTOS_INICIAIS;

		//definindo o intervalo de jogo
		int intervalo;
		int intervalo1;
		int intervalo2;

		printf("Qual sera seu intervalo de jogo?\n");
		printf("[");
		scanf("%d", &intervalo1);
		printf(" e ");
		scanf("%d", &intervalo2);
		printf("]\n");
		
		intervalo = abs(intervalo1 - intervalo2);

		//randomizando o numero secreto
		int numero;
		srand(time(0));
		if(intervalo1 > intervalo2) {
			numero = rand() % intervalo + intervalo2;
		} else
			numero = rand() % intervalo + intervalo1;
		

		//selecinando a dificuldade
		int dificuldade;
		int qtdtentativas;
		
		printf("Selecione sua o numero da sua dificuldade:\n");
		printf("1- Facil, 2- Medio, 3- Dificil\n");
		
		scanf("%d", &dificuldade);
		
		switch(dificuldade) {
			case 1:
				qtdtentativas = QTD_TENTATIVAS_FACIL;
				break;
			case 2: 
				qtdtentativas = QTD_TENTATIVAS_MEDIO;
				break;
			default:
				qtdtentativas = QTD_TENTATIVAS_DIFICIL;
				break;
		}

		//comparando resultados
		for( int i = 1; i <= qtdtentativas; i++) {
		
			int chute;

			printf("Chute um numero\n");
			scanf("%d", &chute);

			//fins de teste
			//printf("%d\n", numero);
		
			if(chute < 0) {
				printf("Apenas numaros positivos sao permitidos!\n");
				i--;
				continue;
			}
			
			int ultimochute;	
			
			if(ultimochute == chute){
				printf("Voce ja chutou esse numero! Tente de novo!\n");
				i--;
				continue;
			}

			acertou = chute == numero;
			int modulo = abs(chute - numero);
			ultimochute = chute;

			if (acertou) {
				break;	
			} else 
				if(modulo >= 1, modulo < 5) {
					printf("Muito quente!\n");
						
				 }else if(modulo >= 5, modulo < 10){
					printf("Bem quente!\n");
						
				 }else if(modulo >= 10, modulo < 20){
					printf("Quente!\n");
						
				 }else if(modulo >= 20, modulo < 30){
					printf("Morno!\n");
						
				 }else if(modulo >= 30, modulo < 40){
					printf("Frio!\n");
					
				 }else if(modulo >= 40){
					printf("Muito frio\n");
				}

			printf("tentativa %do. de %d\n\n", i, qtdtentativas);
			
			if(dificuldade = 1) {
				pontos = pontos - abs(chute - numero) - 30;
			}else if(dificuldade = 2) {
				pontos = pontos - abs(chute - numero) - 15;
			}else if (dificuldade = 3) {
				pontos = pontos - abs(chute - numero) - 5;
			}
			
			
		} 
		//Fim do jogo
		printf("Fim de jogo!\n");
		
		if(!acertou) {
			printf("Voce perdeu!Tente novamente!\n");
		} else {
			printf("Parabens, voce venceu!\n");
			printf("Sua pontuacao foi: %d\n\n", pontos);
		}
		
		printf("Digite 1 se quiser jogar novamente\n");
		scanf("%d", &jogardnv );
		
	} while(jogardnv == 1)
	printf("Fim de jogo!\n");
	printf("Obrigado por jogar!");
} 