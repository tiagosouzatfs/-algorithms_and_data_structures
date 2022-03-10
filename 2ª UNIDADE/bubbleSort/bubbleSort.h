#pragma once

#include "../bubbleSort/bubbleSort.cpp"

struct bubbleSort {
	int* v;
	int tamanho;
};

struct bubbleSort* inicializar(int tamanho) {
	struct bubbleSort* v = (struct bubbleSort*)malloc(sizeof(int) * tamanho);
    v->v = (int*)calloc(tamanho, sizeof(int));
    v->tamanho = tamanho;
	return v;
}

void bubbleSort(int* v, int tamanho) {
	for (int varredura = 0; varredura < tamanho - 1; varredura++) {
		bool trocou = false;
		for (int i = 0; i < tamanho - varredura - 1; i++) {
			if (v[i] > v[i+1]) {
				int temp = v[i];
				v[i] = v[i+1];
				v[i+1] = temp;
				trocou = true;
			}
		}
		if (trocou == false)
			return;
	}
}