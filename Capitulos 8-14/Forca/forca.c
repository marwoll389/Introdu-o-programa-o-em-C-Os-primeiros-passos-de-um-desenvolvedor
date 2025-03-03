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

//abertura do jogo
void abertura () {
	printf("/****************************/\n");
	printf("/	Jogo	de	Forcanesque	*/\n");
	printf("/****************************/\n\n");
}

int palavrajaexiste() {

	FILE* f;

	f = fopen("palavras.txt", "r");

	for(int i = 0; i > qtddepalavras; i++ ) {
		if(novapalavra == )
	}
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
		fprintf(f, "%d", qtd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);
		
		fclose(f);
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
	return contadordeerros() >= 5;
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

//codigo principal
int main() {
	
	abertura();
	adicionarpalavra();
	escolhepalavra();
	//printf("%s\n", palavra);

 	do {
 		desenhaforca();
 		chuta();

 	} while(!ganhou() && !enforcou());
 	if(ganhou) {
 		printf("Parabens, voce ganhou\n");

 	} else 
 		printf("Perdeu!, tente denovo");
 		
}
