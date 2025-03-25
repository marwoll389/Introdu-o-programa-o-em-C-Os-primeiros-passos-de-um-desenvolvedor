struct mapa{
	char** matriz;
	int linhas;
	int colunas;
};

typedef struct mapa MAPA;

void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);
void andanomapa(MAPA*m, int origemx, int origemy, int destinox, int destinoy);
int ehvazia(MAPA* m, int x, int y);
int ehvalida(MAPA* m, int x, int y);
