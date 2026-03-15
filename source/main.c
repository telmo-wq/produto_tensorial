#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <pthread.h>
#include <time.h>
#include <omp.h>


int main(int argc, char *argv[])
{
    int ***array_de_matrizes;
    array_de_matrizes = (int ***)malloc(argc * sizeof(int ***));
    int *tamanhos = (int *)malloc(argc * sizeof(int));

    if (argc == 2){
        printf("AVISO: Devem ser inseridos no minimo dois arquivos\n");
        return 0;
    }

    struct timespec inicio, fim;

    clock_gettime(CLOCK_MONOTONIC, &inicio);

    pthread_t *tids = malloc((argc-1) * sizeof(pthread_t));
    Argumentos *argumentos = malloc((argc-1) * sizeof(Argumentos));

    for (int j = 0; j < argc-1; j++){
        argumentos[j].indice = j;
        argumentos[j].argc = j;
        argumentos[j].argv = argv[j+1];
        argumentos[j].array_de_matrizes = array_de_matrizes;
        argumentos[j].tamanhos = tamanhos;

        pthread_create(&tids[j], NULL, ler_arquivos, &argumentos[j]);
    }

    for (int i = 0; i < argc-1; i++){
        pthread_join(tids[i], NULL);
    }

    free(tids);
    free(argumentos);

    int **matriz_resultado = produto_tensorial(array_de_matrizes[0], array_de_matrizes[1], tamanhos[0], tamanhos[1]);

    int tamanho_resultado = tamanhos[0] * tamanhos[1];

    if (argc > 3){
        for (int arquivo = 3; arquivo < argc; arquivo++){
            matriz_resultado = produto_tensorial(matriz_resultado, array_de_matrizes[arquivo-1], tamanho_resultado, tamanhos[arquivo-1]);
            tamanho_resultado = tamanho_resultado * tamanhos[arquivo-1];
        }
    }

    for (int i = 0; i < tamanho_resultado; i++){
        for (int j = 0; j < tamanho_resultado; j++){
            printf("%d ", matriz_resultado[i][j]);
        }
        printf("\n");
    }

    FILE *arquivo_resultado = fopen("tensor_tmfc.out", "w");

    for (int linha = 0; linha < tamanho_resultado; linha++){
        for (int coluna = 0; coluna < tamanho_resultado; coluna++){
            fprintf(arquivo_resultado, "%d ", matriz_resultado[linha][coluna]);
        }
        fprintf(arquivo_resultado, "\n");
    }

    fclose(arquivo_resultado);

    for (int linha = 0; linha < tamanho_resultado; linha++){
        free(matriz_resultado[linha]);
    }

    free(matriz_resultado);

    for (int matriz = 0; matriz < argc; matriz++){
        for (int linha = 0; linha < tamanhos[matriz]; linha++){
            free(array_de_matrizes[matriz][linha]);
        }
        free(array_de_matrizes[matriz]);
    }
    free(array_de_matrizes);

    free(tamanhos);

    clock_gettime(CLOCK_MONOTONIC, &fim);

    double tempo = ((fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec))/1e9;

    printf("Tempo de execução: %f segundos\n", tempo);


}