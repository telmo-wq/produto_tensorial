#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(int argc, char *argv[])
{
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

        int **matriz = (int **)malloc(tamanho_matriz * sizeof(int *));

        for (int linha = 0; linha < tamanho_matriz; linha++){
            matriz[linha] = (int *)malloc(tamanho_matriz * sizeof(int));
        }

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
        
        for (int i = 0; i < tamanho_matriz; i++){
            free(matriz[i]);
        }

        free(matriz);

        fclose(file);
    }

}