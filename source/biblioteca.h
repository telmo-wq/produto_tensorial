#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int indice;
    int argc;
    char *argv;
    int ***array_de_matrizes;
    int *tamanhos;
} Argumentos;

int contar_matriz(FILE *file);

int **aloca_matriz(int tamanho_matriz);

int **produto_tensorial(int **matriz1, int **matriz2, int tamanho1, int tamanho2);

void *ler_arquivos(void *param);

#endif