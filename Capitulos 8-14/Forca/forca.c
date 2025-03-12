#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

//variáveis globais
char palavra[TAMANHO_PALAVRA];
char chutesanteriores[26];
int chutesdados = 0;
char chute;
int qtddepalavras;
int nummaxchutes;

//abertura do jogo
void abertura () {
	printf("/****************************/\n");
	printf("/	Jogo	de	Forcanesque	*/\n");
	printf("/****************************/\n\n");
}

void adicionarpalavra() {
	char quer;

	printf("Deseja adicionar uma nova palavra ao jogo? [S/N]\n");
	scanf(" %c", &quer);

	if(quer == 'S'){
		char novapalavra[TAMANHO_PALAVRA];
	
		printf("Digite a nova palavra, em maiusculas\n");
		scanf("%s", &novapalavra);

		FILE* f;

		f = fopen("palavras.txt", "r+");
		if(f == 0) {
			printf("Banco de dados nao pode ser acessado\n\n");
			exit(1);
		}
			
	
		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;

		fseek(f, 0, SEEK_SET);
		fprintf(f, "%04d", qtd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);
		
		fclose(f);
	
		printf("Palavra %s adicionada!\n", novapalavra);
	
	}
}

//determinação da palavra da forca
void escolhepalavra() {
	FILE* f;

	f = fopen("palavras.txt", "r");
	if(f == 0) {
		printf("Banco de dados de palavras deu merda\n\n");
		exit(1);
	}

	
	fscanf(f, "%d", &qtddepalavras);

	srand(time(0));
	int randomizador = rand() % qtddepalavras;

	for(int i = 0; i <= randomizador; i++){
		fscanf(f,"%s", &palavra);
	}
	fclose(f);
}

int dificuldade() {
	int dificuldade; 

	printf("Qual dificuldade você quer jogar?\n");
	printf("1- Fácil  2- Médio  3- Difícil\n");
	scanf("%d", &dificuldade);

	switch(dificuldade) {
	case 1:
		nummaxchutes = 8;
		break;

	case 2:
		nummaxchutes = 6;
		break;

	case 3:
		nummaxchutes = 4;
		break;
	}
}

//verificação dos chutes
int jachutou(char letra) {
	int achou = 0;

	for(int j = 0; j < chutesdados; j++) {
 		if(chutesanteriores[j] == letra) {
 				achou = 1;
 				break;
 		}
 	}

 	return achou;

}

//desenha a forca
void desenhaforca() {

	int erros = contadordeerros();

	printf("Voce ja deu %d chutes\n", chutesdados);

 	printf("  _______           \n");
	printf(" |/      |          \n");
	printf(" |      %c%c%c      \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
	printf(" |      %c%c%c      \n", (erros >= 2 ? '\\' : ' '),(erros >= 2 ? '|' : ' '), (erros >= 2 ? '/' : ' '));
	printf(" |       %c         \n", (erros >= 3 ? '|' : ' '));
	printf(" |      %c %c       \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
	printf(" |                  \n");
	printf("_|___               \n");
	
	printf("\n\n");


 	for(int posicao = 0; posicao < strlen(palavra); posicao++) {
 		if(jachutou(palavra[posicao])) {
 			printf("%c ", palavra[posicao]);	
 		} else 
 			printf("_ ");
 		} 	
 		
 		printf("\n");
}

//recebimento do chute
void chuta() {
	int chutevalido = 0;

	while(!chutevalido) {
		
		
		printf("Qual letra voce chuta?\n");
	 	scanf(" %c", &chute);
		
		if(chute >= 65 && chute <= 90) {
	 		chutevalido =  1;
	 	} else
	 		printf("Chute invalido, apenas letras maisculas\n");
	 		printf("Tente outra letra\n\n");
	 }

	 	if(letraexiste(chute)) {
	 		printf("Voce acertou, a palavra tem a letra %c\n\n", chute);
	 	} else
	 		printf("Voce errou, a palavra nao tem a letra %c\n\n", chute);

	 	chutesanteriores[chutesdados] = chute;
	 	chutesdados++;
	 	chutevalido = 0;
}

int letraexiste(char letra) {

	for(int j = 0; j < strlen(palavra); j++) {
		if(letra == palavra[j]) {
			return 1;
		}
	}
	return 0;
}

int contadordeerros() {
	int erros = 0;

	for(int i = 0; i < chutesdados; i++){

		if(!letraexiste(chutesanteriores[i])) {	
			erros++;
		}
	}
	return erros;
}

//enforcar
int enforcou() {
	return contadordeerros() >= nummaxchutes;
}

//ganhar
int ganhou() {
	for(int i = 0; i < strlen(palavra); i++) {
		if(!jachutou(palavra[i])) {
			return 0;
		}
	}
	return 1;
}

int ranking(int resultado) {
	FILE* f;

	f = fopen("ranking.txt", "w+");
	if(f == NULL){
		printf("Arquivo nao pode ser acessado");
		exit(1);
	}

	fseek(f, 0, SEEK_SET);
	if(resultado) {
		fprintf(f, "sua pontuacao foi fodinha");
		//fprintf(f, "voce ganhou com %d chutes", chutesdados);
	} else 
		fprintf(f, "nao tao fodinha");
	fclose(f);
}

//codigo principal
int main() {
	
	abertura();
	escolhepalavra();
	dificuldade();

 	do {
 		desenhaforca();
 		chuta();

 	} while(!ganhou() && !enforcou());
 	if(ganhou) {
 		printf("Parabens, voce ganhou\n\n");
		adicionarpalavra();
 		printf("Fim de jogo!");

 	} else 
 		printf("Perdeu!, tente denovo\n");
 		printf("Fim de jogo!");

 	ranking(ganhou());
}
