#include <stdio.h>
#include <string.h>

void abertura () {
	printf("/****************************/\n");
	printf("/	Jogo	de	Forcanesque	*/\n");
	printf("/****************************/\n\n");

}

int main() {
	
	abertura();

 	int acertou = 0;
 	int enforcou = 0;

	char chutesanteriores[26];
 	int tentativas = 0;
 	char chute;

 	char palavra[10];
 	sprintf(palavra, "XESQUE");

 	do {
 
 		printf("Qual letra voce chuta?\n");
 		scanf(" %c", &chute);

 		chutesanteriores[tentativas] = chute;
 		tentativas++;

 		for(int posicao = 0; posicao < strlen(palavra); posicao++) {
 			
 			int achou = 0;

 			for(int j = 0; j < tentativas; j++) {
 				if(chutesanteriores[j] == palavra[posicao]) {
 					achou = 1;
 					break;
 				}
 			}


 			if(achou) {
 				printf("%c ", palavra[posicao]);
 			} else 
 				printf("_ ");
 		
 		} 
 		printf("\n");

 	} while(!acertou && !enforcou);
}
