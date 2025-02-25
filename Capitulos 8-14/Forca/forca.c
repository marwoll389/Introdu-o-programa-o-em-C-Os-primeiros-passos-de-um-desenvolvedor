#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

//variáveis globais
char palavra[10];
char chutesanteriores[26];
int chutesdados = 0;

//abertura do jogo
void abertura () {
	printf("/****************************/\n");
	printf("/	Jogo	de	Forcanesque	*/\n");
	printf("/****************************/\n\n");
}

void adicionarpalavra() {
	char quer;

	printf("Deseja adicionar uma nova palavra ao jogo? [S/N]\n");
	scanf("%s", &quer);

	if(quer == 'S'){
		char novapalavra[20];

		printf("Digite a nova palavra, em maisculas");
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

	int qtddepalavras;
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

	printf("Voce ja deu %d chutes\n", chutesdados);

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

	char chute;
	printf("Qual letra voce chuta?\n");
 	scanf(" %c", &chute);

 	chutesanteriores[chutesdados] = chute;
}

//enforcar
int enforcou() {
	int erros = 0;

	for(int i = 0; i < chutesdados; i++){

		int existe = 0;

		for(int j = 0; j < strlen(palavra); j++) {
			if (chutesanteriores[i] == palavra[j]) {
				existe = 1;
				break;	
			}
		}
		if(!existe) erros++;
	}
	return erros >= 5;
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
	escolhepalavra();
	printf("%s\n", palavra);

 	do {
 		desenhaforca();
 		chuta();

 		chutesdados++;

 	} while(!ganhou() && !enforcou());
}
