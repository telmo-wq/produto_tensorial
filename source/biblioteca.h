#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>

int contar_matriz(FILE *file);

int **aloca_matriz(int tamanho_matriz);

int **produto_tensorial(int **matriz1, int **matriz2);

int **mudar_tamanho(int **matriz, int antigo_tamanho, int novo_tamanho);

#endif