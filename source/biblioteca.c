#include "biblioteca.h"
#include <math.h>
#include <stdlib.h>


int contar_matriz(FILE *file){
    int cont_linha = 0;
    int valor;
    while(fscanf(file, "%d", &valor) == 1){
        cont_linha++;
    }
    rewind(file);

    if (sqrt(cont_linha) == (int)sqrt(cont_linha)){
        return (int)sqrt(cont_linha);

    }else{
        return 0;

    }
    
}

int **aloca_matriz(int tamanho_matriz){
    int **nova_matriz = (int **)malloc(tamanho_matriz * sizeof(int));

    for (int linha = 0; linha < tamanho_matriz; linha++){
            nova_matriz[linha] = (int *)malloc(tamanho_matriz * sizeof(int));
    }

    for (int i = 0; i < tamanho_matriz; i++){
            for (int j = 0; j < tamanho_matriz; j++){
                nova_matriz[i][j] = 1;
        }
     }

     return nova_matriz;
}


int **produto_tensorial(int **array_de_matrizes, int *tamanhos, int argc){
    for(int i = 0; i < argc; i++){
        
    }
}