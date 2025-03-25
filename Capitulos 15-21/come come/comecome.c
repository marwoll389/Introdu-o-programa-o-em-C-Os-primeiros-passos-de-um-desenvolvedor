#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comecome.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

void encontramapa(MAPA* m, POSICAO* p, char c){

	for(int i = 0; i < m->linhas; i++) {
		for(int j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == c){
				p->x = i;
				p->y = j;
				return;
			}
		}
	}
}

int acabou(){
	return 0;
}

void move(char direcao){
	
	if(!ehdirecao(direcao))
		return;;

	int proximox = heroi.x;
	int proximoy = heroi.y;

	switch(direcao){
		case 'a':
			proximoy--;
			break;
		case 'd':
			proximoy++;
			break;
		case 'w':
			proximox--;
			break;
		case 's':
			proximox++;
			break;
	}
	
	if(!ehvalida(&m, proximox, proximoy));
		return;

	if(!ehvazia(&m, proximox, proximoy));
		return;

	andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;

}

int ehdirecao(char direcao) {
	return
		direcao == 'a' ||
		direcao == 'd' ||
		direcao == 'w' ||
		direcao == 's';
}

int main() {

	lemapa(&m);
	encontramapa(&m, &heroi, '@');

	do {

		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);

	} while(!acabou());

	liberamapa(&m);
}