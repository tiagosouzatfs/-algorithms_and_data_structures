#include <stdio.h>
#include <stdlib.h>
#include "bubbleSort.h"

using namespace std;
int main() {
	int tamanho = 10;
	int* v;
	struct bubbleSort* vetor;

	inicializar(tamanho);
	bubbleSort(v, tamanho);

	free(v);
	return 0;
}
