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
	
	if( direcao != 'a' &&
		direcao != 'w' &&
		direcao != 's' &&
		direcao != 'd') {

		return;
	}
	
	m.matriz[heroi.x][heroi.y] = '.';

	switch(direcao){
	case 'a':
		m.matriz[heroi.x][heroi.y-1] = '@';
		heroi.y--;
		break;
	case 'd':
		m.matriz[heroi.x][heroi.y+1] = '@';
		heroi.y++;
		break;
	case 'w':
		m.matriz[heroi.x-1][heroi.y] = '@';
		heroi.x--;
		break;
	case 's':
		m.matriz[heroi.x+1][heroi.y] = '@';
		heroi.x++;
		break;
	}
	

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