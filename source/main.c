#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(int argc, char *argv[])
{
    int ***array_de_matrizes;
    array_de_matrizes = (int ***)malloc(argc * sizeof(int ***));
    int *tamanhos = (int *)malloc(argc * sizeof(int));

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

        array_de_matrizes[i-1] = matriz;
        tamanhos[i-1] = tamanho_matriz;

        fclose(file);
    }


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


}