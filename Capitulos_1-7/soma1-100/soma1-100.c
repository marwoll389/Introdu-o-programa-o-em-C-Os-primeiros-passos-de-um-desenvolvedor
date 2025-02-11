#include <stdio.h>

int main() {

	int numeroinicial = 1;
	int numerototal = 0;

	for(int i = 1; i <= 100; i++) {

		numerototal = numerototal + numeroinicial;
		numeroinicial = numeroinicial + 1;
	}

	printf("%d", numerototal);
}