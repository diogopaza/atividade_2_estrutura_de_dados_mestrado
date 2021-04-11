#include <stdio.h>
#include <stdlib.h>

int main(){
    //LENDO DADOS
    /*
    FILE *file;
    file = fopen("string.txt", "r");
    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }

    char frase[100];

    while(fgets(frase, 100, file) != NULL){
        printf("%s", frase);
    } 
    fclose(file);
    */
/*
   //ESCREVENDO DADOS PARTE 1
    FILE *file = fopen("teste.txt", "w");
    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }    
    for (int i=1; i<=10; i++)
        fprintf(file, "%d\n", i);
    fclose(file);
*/   
    FILE *arquivo;
    arquivo = fopen("testando.txt", "w");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }  
    fprintf(arquivo, "Busca\nValor \nTempo");
    fclose(arquivo);
    return 0;
}
