#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dados.h"
#include "heap.h"

int main() {

	clock_t inicio, fim;
	double total = 0.0;
	double media = 0.0;

	int i;
	for(i = 1; i <= 20; i++){

		int n_linhas = 0;

		// dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);
		dado_t **dados = ler_dados_csv("07_camera_temp.csv", &n_linhas);

		heap_t * heap;

		inicio = clock();
		heap = heap_sort(dados, n_linhas);
		fim = clock();

		liberar_heap(heap, n_linhas);

		total = (double) ((fim - inicio) * 1000) / (CLOCKS_PER_SEC);
		media += total;

		//puts("\n---------------------------------\n");
		//exibe_dados(dados, n_linhas);

		printf("Tempo decorrido: %lf (ms)\n", total);

		liberar_dados(dados, n_linhas);

	}

	printf("Média do Tempo Decorrido: %lf (ms)\n", media / (i - 1));

	return EXIT_SUCCESS;
}
