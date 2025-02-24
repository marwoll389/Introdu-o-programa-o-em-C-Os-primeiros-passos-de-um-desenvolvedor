#include <stdio.h>
#include <string.h>

char palavra[10];
char chutesanteriores[26];
int tentativas = 0;

void abertura () {
	printf("/****************************/\n");
	printf("/	Jogo	de	Forcanesque	*/\n");
	printf("/****************************/\n\n");
}

int jachutou(char letra) {
	int achou = 0;

	for(int j = 0; j < tentativas; j++) {
 		if(chutesanteriores[j] == letra) {
 				achou = 1;
 				break;
 		}
 	}
 //	if(achou = 0) {
 //		(*erros)++;
 //	}
 	return achou;

}

void desenhaforca() {

	printf("Voce ja deu %d chutes\n", tentativas);

 		for(int posicao = 0; posicao < strlen(palavra); posicao++) {

 			if(jachutou(palavra[posicao])) {
 				printf("%c ", palavra[posicao]);
 			} else 
 				printf("_ ");
 		
 		} 
 		printf("\n");
 		//if(erros > 0) {
 		//	printf("Erro %d de 6", erros);
 	//	}
}

void chuta() {

	char chute;
	printf("Qual letra voce chuta?\n");
 	scanf(" %c", &chute);

 	chutesanteriores[tentativas] = chute;

}


void escolhepalavra() {
	sprintf(palavra, "XESQUE");
}

int main() {
	
	int erros = 0;	
 	int acertou = 0;
 	int enforcou = 0;
	
	abertura();
	escolhepalavra();

 	do {
 		if(erros == 5) {
 			enforcou = 1;
 		}

 		desenhaforca(&erros);
 		chuta();

 		tentativas++;

 	} while(!acertou && !enforcou);
}
