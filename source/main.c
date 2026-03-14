#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <pthread.h>
#include <time.h>

typedef struct {
    int ***array_de_matrizes;
    int *tamanhos;
    int argc;
} argumentos_threads;

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

    pthread_t tid;
    pthread_attr_t attr;

    pthread_create(&tid, &attr, calcular_tensorial, &argumentos_threads);

    clock_gettime(CLOCK_MONOTONIC, &inicio);

    for (int i = 1; i < argc; i++){
        int num;
        FILE *file = fopen(argv[i], "r");

        if (file == NULL){
            printf("ERRO! Arquivo não encontrado ou inexistente\n");

            return 0;
        }

        int tamanho_matriz = contar_matriz(file);
        
        if (tamanho_matriz == 0){
            printf("ERRO! Matriz nao quadrada\n");
            return 0;
        }

        int **matriz = aloca_matriz(tamanho_matriz);

        for (int i = 0; i < tamanho_matriz; i++){
            for (int j = 0; j < tamanho_matriz; j++){
                fscanf(file, "%d", &num);
                matriz[i][j] = num;
            }
        }

        array_de_matrizes[i-1] = matriz;
        tamanhos[i-1] = tamanho_matriz;

        fclose(file);
    }



    for (int matriz = 0; matriz < argc; matriz++){
        for (int linha = 0; linha < tamanhos[matriz]; linha++){
            free(array_de_matrizes[matriz][linha]);
        }
        free(array_de_matrizes[matriz]);
    }
    free(array_de_matrizes);

    free(tamanhos);

    clock_gettime(CLOCK_MONOTONIC, &fim);

    printf("Tempo de execução: %f segundos\n", tempo);


}