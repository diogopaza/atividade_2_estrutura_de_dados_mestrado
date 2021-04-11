#include <stdio.h>

int main(){
    //int lixo[10];
    int num_componentes = 10;
    int *lixo;
    lixo = malloc(num_componentes * sizeof(int));
    int indice;

    for(indice=0 ; indice < 10 ; indice++)
        printf("Lixo na posicao %d: %d\n", indice, lixo[indice]);    
}