#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void lemapa(MAPA* m) {

	FILE* f = fopen("mapa.txt", "r");
	if(f == NULL) {
		printf("Erro ao ler o mapa");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
	alocamapa(m);

	for(int i = 0; i < m->linhas; i++){
		fscanf(f, "%s", m->matriz[i]);
	}

	fclose(f);
}
void alocamapa(MAPA* m) {

	m->matriz = malloc(sizeof(char*) * m->linhas);

	for(int i = 0; i < m->linhas; i++){
		m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
	}
}
void liberamapa(MAPA* m){
	for(int i = 0; i < m->linhas; i++){
		free(m->matriz[i]);
	}

	free(m->matriz);
}
void imprimemapa(MAPA* m){
	for(int i = 0; i < m->linhas; i++){
		printf("%s\n", m->matriz[i]);
	}
}
int ehvalida(MAPA* m, int x, int y) {
	if(x >= m->linhas)
		return 0;
	if(y >= m->colunas)
		return 0;

	return 1;
}

int ehvazia(MAPA* m, int x, int y){
	return m->matriz[x][y] == '.';
}

void andanomapa(MAPA* m, int origemx, int origemy, int destinox, int destinoy) {
	char personagem = m->matriz[origemx][origemy];
	m->matriz[destinox][destinoy] = '@';
	m->matriz[origemx][origemy] = '.';
}