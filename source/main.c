#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(int argc, char *argv[])
{
    int ***array_de_matrizes;
    array_de_matrizes = (int ***)malloc(argc * sizeof(int));

    int *tamanhos;
    tamanhos = (int *)malloc(argc * sizeof(int));



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

        printf("%d\n", tamanho_matriz);

        int **matriz = aloca_matriz(tamanho_matriz);

        for (int i = 0; i < tamanho_matriz; i++){
            for (int j = 0; j < tamanho_matriz; j++){
                fscanf(file, "%d", &num);
                matriz[i][j] = num;
            }
        }


        for (int i = 0; i < tamanho_matriz; i++){
            for (int j = 0; j < tamanho_matriz; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }

        array_de_matrizes[i] = matriz;
        
        for (int i = 0; i < tamanho_matriz; i++){
            free(matriz[i]);
        }

        free(matriz);

        fclose(file);
    }

    int **matriz_resultado = produto_tensorial(array_de_matrizes[1], array_de_matrizes[2]);

    size_t tam = sqrt(sizeof(matriz_resultado));

    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            printf("%d ", matriz_resultado[i][j]);
        }
        printf("\n");
    }


}