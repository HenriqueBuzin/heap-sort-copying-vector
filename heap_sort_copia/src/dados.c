#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"

struct dados {
    int amostra;
    float temperatura;
    char tempo[64];
};

dado_t * criar_dado (int amostra, float temperatura, char * timestamp){

    dado_t * dado = malloc(sizeof(struct dados));

    dado->amostra = amostra;
    dado->temperatura = temperatura;
    strcpy(dado->tempo, timestamp);

    return dado;
}

dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas){
    char texto[64];
    int i=0;
    *n_linhas = 0;

    FILE *fp = fopen(nome_do_arquivo,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    /* Ignora primeira linha */
    fseek(fp, 19, SEEK_SET);

    /* Contar todas as linhas: use while e fgets() */
    while(fgets(texto, sizeof(texto), fp) != NULL){
    	(*n_linhas)++;
    }

    /* Aloque memória:
     * Agora é um vetor de ponteiros */
     dado_t **dados;
     dados = malloc(sizeof(struct dados *) * *n_linhas);

    rewind(fp);
     /* Ignora primeira linha */
    fscanf(fp, "%*[^\n]");

    int amostra;
    float temperatura;
    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3){
        // printf("Lido %d, %f, %s\n", amostra, temperatura, texto);

        /* Cria um novo dado abstrato e armazena a sua referência */
        dados[i] = criar_dado(amostra, temperatura, texto);

        i++;
    }

    fclose(fp);
    return dados;
}

void exibe_dado(dado_t * dado){

	printf("%d %f %s \n", dado->amostra, dado->temperatura, dado->tempo);

}

void exibe_dados(dado_t ** dados, int n_linhas){
	for(int i = 0; i < n_linhas; i++){
		exibe_dado(dados[i]);
	}
}

void liberar_dados(dado_t **vetor, int n_linhas){

	if(vetor == NULL){
		perror("liberar_dados");
		exit(-1);
	}

	for (int i = 0; i < n_linhas; i++){
		free(vetor[i]);
	}
	free(vetor);
}

float retornar_temperatura(dado_t * dado){
	return (dado->temperatura);
}

int retornar_amostra(dado_t * dado){
	return (dado->amostra);
}
