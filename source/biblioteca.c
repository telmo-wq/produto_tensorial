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
    int **nova_matriz = (int **)malloc(tamanho_matriz * sizeof(int **));

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



int **produto_tensorial(int **matriz1, int **matriz2, int tamanho1, int tamanho2){

    int **matriz_resultado = aloca_matriz(tamanho1 * tamanho2);

    int tamanho_resultado = tamanho1 * tamanho2;

    #pragma openmp parallel for collapse(2)
    for (int i = 0; i < tamanho_resultado; i++){ 
        for (int j = 0; j < tamanho_resultado; j++){
            matriz_resultado[i][j] = matriz_resultado[i][j] * matriz1[i/(tamanho2)][j/(tamanho2)] * matriz2[i%(tamanho2)][j%(tamanho2)];
        }
    } 

    return matriz_resultado;


}
