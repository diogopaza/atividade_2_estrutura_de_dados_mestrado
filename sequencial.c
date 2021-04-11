#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t t; //variável para armazenar tempo
double tempo_execucao;
int valor_buscado;
char nome_busca[100];

struct Pair {
	int left, right;
};

int min(int a, int b) {
	return a < b ? a : b;
}
int buscaBinaria(int vetor[], int item, int tamanho){

strcpy( nome_busca, "Busca_Binaria");
valor_buscado = item;
int inicio = 1;
int fim = tamanho - 1;
int meio;
t = clock(); //armazena tempo
while (inicio <= fim){
	
	meio = (inicio + fim) / 2;

	if (vetor[meio] == item ){
        t = clock() - t; //tempo final - tempo inicial
        tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
		return meio;
		
	}
	if (item > vetor[meio]){

		inicio = meio + 1;
		
	}
	else{
		fim = meio - 1;
	}
}
    t = clock() - t; //tempo final - tempo inicial
    tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
    return -1;

}

struct Pair jumpSearchUtil(int arr[], int n, int val, int low, int high) {
    int left = low;
    int step = (int) sqrt(high - low);
    int right = 0;
	struct Pair p;
	
    while (left < high && arr[left] <= val) {
        right = min(left + step, high);

        if (arr[left] <= val && arr[right] >= val) {
            p.left = left;
            p.right = right;
            
			return p;
        }

        left = right;
    }
    
	p.left = -1;

    return p;
}

int jumpSearch(int arr[], int n, int val) {

    strcpy( nome_busca, "Jump_Search");
    valor_buscado = val;
    int low = 0, high = n - 1;
    t = clock(); //armazena tempo
    while (high - low > 1) {
        struct Pair p = jumpSearchUtil(arr, n, val, low, high);

        if (p.left == -1) {
            t = clock() - t; //tempo final - tempo inicial
            tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
            return -1;
        }

        low = p.left;
        high = p.right;
    }
    t = clock() - t; //tempo final - tempo inicial
    tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
    return arr[low] == val ? low : arr[high] == val ? high : -1;
}




int buscaSequencial(int v[],int tamanho, int pesq)
{
    int i;
    strcpy( nome_busca, "Busca_Sequencial");
    valor_buscado = pesq;
    t = clock(); //armazena tempo    
     for(i=0;i<tamanho;i++)
     {
         
          if(v[i]==pesq)
          {
            t = clock() - t; //tempo final - tempo inicial
            tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
            return i; /* encontrou */
          }
     }
    t = clock() - t; //tempo final - tempo inicial
    tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
    return -1;
}

int buscaSequencialVetorOrdenado(int vetor_ordenado[],int tamanho, int pesq)
{
    int i;
    strcpy( nome_busca, "Busca_Sequencial_Ordenado");
    valor_buscado = pesq;
    t = clock(); //armazena tempo
    for (i = 0; i < tamanho; i++) {
        if (vetor_ordenado[i] == pesq){
            t = clock() - t; //tempo final - tempo inicial
            tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
            return i; /* encontrou */
        } 
        if (vetor_ordenado[i] > pesq){
            t = clock() - t; //tempo final - tempo inicial
            tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
            return -1; /* não adianta continuar procurando */
        } 
    }
    /* foi até o final e não encontrou */
    t = clock() - t; //tempo final - tempo inicial
    tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
    return -1;
}


/*
void executaTesteBuscaSequencial(int vet[], int valor_buscado[], int tamanho_vetor){
    int resultado, valor_pesquisado;
    clock_t t; //variável para armazenar tempo
    t = clock(); //armazena tempo
    resultado = buscaSequencial(vet,tamanho_vetor,valor_buscado);
    t = clock() - t; //tempo final - tempo inicial
    //imprime o tempo na tela
    printf("Busca Sequencial valor encontrado na posição %d\n", resultado);
    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    
}

void executaTesteBuscaSequencialVetorOrdenado(int vetorOrdenado[], int valor_buscado[], int tamanho_vetor){
    int resultado,valor=0, valor_pesquisado;
    clock_t t; //variável para armazenar tempo
    t = clock(); //armazena tempo
    resultado = buscaSequencialVetorOrdenado(vetorOrdenado,tamanho_vetor,valor_buscado);
    t = clock() - t; //tempo final - tempo inicial
    //imprime o tempo na tela
    printf("Busca Sequencial Vetor Ordenado valor encontrado na posição %d\n", resultado);
    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    
}
*/
//retorna valores para preencher o vetor
int preencheVetor(int menor, int maior)
{
    int k;
    k = (rand() % maior) + menor;
    return k;
}

void sortearNumerosTestarALgoritmos(int vetor[],int menor, int maior){
     
     for(int i = 0; i < 100; i++)
    {
       vetor[i] = rand() % maior + menor;
       //printf("Numero sorteado é [%d] : %d \n",i, vetor[i]);
    }
}

void ordernarVetor(int vetorN[], int tamanho)
{
int i, j,x;
int aux;

for(i = 0; i < tamanho; i++)
{
    for(j = 0; j < tamanho; j++)
    {
        if(vetorN[i] < vetorN[j])
        {
            aux = vetorN[i];
            vetorN[i] = vetorN[j];
            vetorN[j] = aux;            
        }
    }
    }
    
    
}

void exibirVetor(int vetorN[], int tamanho)
{
int i=0;

for(i = 0; i < tamanho; i++)
{
    printf("posicao [%d] com valor de %d\n",i, vetorN[i]);
}
}

int main () {
    srand(time(NULL));
    int i,TAM=1024;
    int* vetorPrincipal = (int*) malloc(TAM * sizeof(int));
    int* vetorOrdenar = (int*) malloc(TAM * sizeof(int));
    //int vetorPrincipal[TAM];
    //int vetorOrdenar[TAM];
    int numerosSorteados[100];
    
    
    for(i = 0; i < 1024; i++)
    {
        int valor;
        valor = preencheVetor(0, 5000);
        vetorPrincipal[i] = valor;
        vetorOrdenar[i] = valor;
        //printf("valor vetor princiapal %d\n",vetorPrincipal[i]);
        //printf("valor vetor ordenar %d\n",vetorOrdenar[i]);
    }

    
    sortearNumerosTestarALgoritmos(numerosSorteados, 0, 2000);
    ordernarVetor(vetorOrdenar, TAM);
   /* for(i = 0; i < 100; i++)
    {
        int resultado=0;
        //executaTesteBuscaSequencial(vetorPrincipal,numerosSorteados[i], TAM);
       // executaTesteBuscaSequencialVetorOrdenado(vetorOrdenar,numerosSorteados[i], TAM);
        resultado = buscaSequencialVetorOrdenado(vetorOrdenar,TAM,numerosSorteados[i], *tempo_resposta);
        printf("resultado %d\n", resultado);
    }*/
    //GRAVANDO EM ARQUIVO
    FILE *arquivo;
    arquivo = fopen("relatorio.csv", "w");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }   
    int resultado=0;
    fprintf(arquivo,"Busca;Posição;Valor_Pesquisado;Tempo_Resposta\n");
    //int n_jump_search = sizeof(vetorPrincipal) / sizeof(vetorPrincipal[0]);

    for(i = 0; i < 100; i++)    
    {
        
        resultado = buscaSequencial(vetorOrdenar,TAM,numerosSorteados[i]);
        printf("%s %d %d %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        fprintf(arquivo, "%s; %d; %d; %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        resultado = buscaSequencialVetorOrdenado(vetorOrdenar,TAM,numerosSorteados[i]);
        printf("%s %d %d %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        fprintf(arquivo, "%s; %d; %d; %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        resultado = buscaBinaria(vetorOrdenar,numerosSorteados[i],TAM);
        printf("%s %d %d %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        fprintf(arquivo, "%s; %d; %d; %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        resultado = jumpSearch(vetorOrdenar,TAM,numerosSorteados[i]);
        printf("%s %d %d %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        fprintf(arquivo, "%s; %d; %d; %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);

    }      
    
    fclose(arquivo);
    return 0;
    
    
    //exibirVetor(vetorOrdenar, TAM);


   return 0;


}
