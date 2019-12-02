#ifndef HEAP_INCLUDED

#include "dados.h"

typedef struct heaps heap_t;

int pai(int i);

int esquerda(int i);

int direita(int i);

void max_heapify(heap_t * heap, int i);

float obter_temperatura(heap_t * heap, int i);

void swap(heap_t * heap, int a, int b);

heap_t * build_heap(dado_t ** dados, int n_linhas);

heap_t * heap_sort(dado_t ** dados, int n_linhas);

void heap2dados(heap_t * heap, dado_t ** dados);

int set_tamanho_heap(heap_t * heap, int tam);

int get_tamanho_heap(heap_t * heap);

void liberar_heap(heap_t * heap, int n_linhas);

#endif
