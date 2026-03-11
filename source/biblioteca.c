#include "biblioteca.h"
#include <math.h>


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