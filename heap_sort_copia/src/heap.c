#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "dados.h"
#include "heap.h"

struct heaps {
	int tamanho;
	dado_t **dados;
};

int pai(int i) {
	return floor((i - 1) / 2);
}

int esquerda(int i) {
	return (2 * i + 1);
}

int direita(int i) {
	return (2 * i + 2);
}

float obter_temperatura(heap_t *heap, int i) {
	return (retornar_temperatura(heap->dados[i]));
}

void swap(heap_t *heap, int a, int b) {
	dado_t *aux = heap->dados[a];
	heap->dados[a] = heap->dados[b];
	heap->dados[b] = aux;
}

void max_heapify(heap_t *heap, int i) {
	int e = esquerda(i);
	int d = direita(i);

	int maior = 0;
	if (e < get_tamanho_heap(heap)
			&& (obter_temperatura(heap, e) > obter_temperatura(heap, i))) {
		maior = e;
	} else {
		maior = i;
	}

	if (d < get_tamanho_heap(heap)
			&& (obter_temperatura(heap, d) > obter_temperatura(heap, maior))) {

		maior = d;
	}

	if (maior != i) {
		swap(heap, i, maior);
		max_heapify(heap, maior);
	}

}

heap_t* build_heap(dado_t **dados, int n_linhas) {

	heap_t *heap = malloc(sizeof(struct heaps));

	heap->tamanho = n_linhas;
	heap->dados = malloc(sizeof(struct dados*) * n_linhas);

	int i = 0;
	for (i = 0; i < n_linhas; i++) {
		heap->dados[i] = dados[i];
	}

	for (int i = heap->tamanho / 2 - 1; i >= 0; i--) {
		max_heapify(heap, i);
	}

	return heap;
}

heap_t* heap_sort(dado_t **dados, int n_linhas) {

	heap_t *heap = build_heap(dados, n_linhas);

	for (int i = n_linhas - 1; i >= 1; i--) {

		swap(heap, 0, i);

		set_tamanho_heap(heap, get_tamanho_heap(heap) - 1);

		max_heapify(heap, 0);

		/*
			for(int a = 0; a < n_linhas; a++){
				printf("%.1f\t", obter_temperatura(heap, a));
			}
			puts("");
		*/

	}

	heap->tamanho = n_linhas;
	heap2dados(heap, dados);

	return heap;

}

void heap2dados(heap_t *heap, dado_t **dados) {
	for (int i = 0; i < heap->tamanho; i++) {
		dados[i] = heap->dados[i];
	}
}

int set_tamanho_heap(heap_t *heap, int tam) {
	heap->tamanho = tam;
	return tam;
}

int get_tamanho_heap(heap_t *heap) {
	return (heap->tamanho);
}

void liberar_heap(heap_t * heap, int n_linhas){

	free(heap->dados);
	free(heap);

}
