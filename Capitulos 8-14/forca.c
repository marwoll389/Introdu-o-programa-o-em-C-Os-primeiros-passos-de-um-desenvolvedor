#include <stdio.h>
#include <string.h>

char palavra[10];
char chutesanteriores[26];
int chutesdados = 0;

void abertura () {
	printf("/****************************/\n");
	printf("/	Jogo	de	Forcanesque	*/\n");
	printf("/****************************/\n\n");
}

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

void chuta() {

	char chute;
	printf("Qual letra voce chuta?\n");
 	scanf(" %c", &chute);

 	chutesanteriores[chutesdados] = chute;

}


void escolhepalavra() {
	sprintf(palavra, "XESQUE");
}

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

int ganhou() {
	for(int i = 0; i < strlen(palavra); i++) {
		if(!jachutou(palavra[i])) {
			return 0;
		}
	}
	return 1;
}

int main() {
	
	abertura();
	escolhepalavra();

 	do {
 		//if(erros == 5) {
 		//	enforcou = 1;
 		//}

 		desenhaforca();
 		chuta();

 		chutesdados++;

 	} while(!ganhou() && !enforcou());
}
