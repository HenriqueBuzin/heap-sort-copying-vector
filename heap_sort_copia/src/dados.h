#ifndef DADO_H_INCLUDED

typedef struct dados dado_t;

dado_t * criar_dado (int amostra, float temperatura, char * timestamp);

dado_t **ler_dados_csv(char *nome_do_arquivo, int * n_linhas);

void exibe_dado(dado_t * dado);

void exibe_dados(dado_t ** dados, int linhas);

void liberar_dados(dado_t **vetor, int n_linhas);

float retornar_temperatura(dado_t * dado);

int retornar_amostra(dado_t * dado);

#endif
