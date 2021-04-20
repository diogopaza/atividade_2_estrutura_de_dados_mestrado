#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t t,tempo_ordenacao; //variável para armazenar tempo
double tempo_execucao, tempo_ordenar_vetor = 0, tempo_total_busca;
int valor_buscado,TAM=4096;
char nome_busca[100];


struct Pair {
	int left, right;
};

int min(int a, int b) {
	return a < b ? a : b;
}
int buscaBinaria(int vetor[], int item, int tamanho){

strcpy( nome_busca, "Binaria");
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
        tempo_total_busca = tempo_execucao + tempo_ordenar_vetor;
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
    tempo_total_busca = tempo_execucao + tempo_ordenar_vetor;

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

    strcpy( nome_busca, "Jump");
    valor_buscado = val;
    int low = 0, high = n - 1;
    t = clock(); //armazena tempo
    while (high - low > 1) {
        struct Pair p = jumpSearchUtil(arr, n, val, low, high);

        if (p.left == -1) {
            t = clock() - t; //tempo final - tempo inicial
            tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
            tempo_total_busca = tempo_execucao + tempo_ordenar_vetor;
            return -1;
        }

        low = p.left;
        high = p.right;
    }
    
    t = clock() - t; //tempo final - tempo inicial
    tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
    tempo_total_busca = tempo_execucao + tempo_ordenar_vetor;
    return arr[low] == val ? low : arr[high] == val ? high : -1;
}




int buscaSequencial(int v[],int tamanho, int pesq)
{
    int i;
    strcpy( nome_busca, "Sequencial");
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
    strcpy( nome_busca, "Ordenado");
    valor_buscado = pesq;
    t = clock(); //armazena tempo
    for (i = 0; i < tamanho; i++) {
        if (vetor_ordenado[i] == pesq){
            t = clock() - t; //tempo final - tempo inicial
            tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
            tempo_total_busca = tempo_execucao + tempo_ordenar_vetor;
            return i; /* encontrou */
        }
        if (vetor_ordenado[i] > pesq){
            t = clock() - t; //tempo final - tempo inicial
            tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
            tempo_total_busca = tempo_execucao + tempo_ordenar_vetor;
            return -1; /* não adianta continuar procurando */
        }
    }
    /* foi até o final e não encontrou */
    t = clock() - t; //tempo final - tempo inicial
    tempo_execucao = (double)t / (CLOCKS_PER_SEC/1000);//conversão para double
    return -1;
}

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
tempo_ordenacao = clock(); //armazena tempo
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
tempo_ordenacao = clock() - tempo_ordenacao; //tempo final - tempo inicial
tempo_ordenar_vetor = (double)tempo_ordenacao / (CLOCKS_PER_SEC/1000);//conversão para double
printf("%lf", tempo_ordenar_vetor);
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
    int i;
    int* vetorPrincipal = (int*) malloc(TAM * sizeof(int));
    int* vetorOrdenar = (int*) malloc(TAM * sizeof(int));
    int numerosSorteados[100];


    for(i = 0; i < TAM; i++)
    {
        int valor;
        valor = preencheVetor(0, 10000);
        vetorPrincipal[i] = valor;
        vetorOrdenar[i] = valor;
    }


    sortearNumerosTestarALgoritmos(numerosSorteados, 0, 5000);
    ordernarVetor(vetorOrdenar, TAM);
 
    //GRAVANDO EM ARQUIVO
    FILE *arquivo;
    arquivo = fopen("tabela.csv", "w");
    if(arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo\n");
        getchar();
        exit(1);
    }
    int resultado=0;
    exibirVetor(vetorOrdenar, TAM);
    fprintf(arquivo,"Busca;Posicao;Valor_Pesquisado;Tempo_Resposta;Tempo_Ordenar_Vetor;Tempo_Total_Busca\n");
    
    for(i = 0; i < 100; i++)
    {

        resultado = buscaSequencial(vetorPrincipal,TAM,numerosSorteados[i]);
        //printf("%s %d %d %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        fprintf(arquivo, "%s; %d; %d; %lf; %d; %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao,0, tempo_execucao);
        resultado = buscaSequencialVetorOrdenado(vetorOrdenar,TAM,numerosSorteados[i]);
        //printf("%s %d %d %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        fprintf(arquivo, "%s; %d; %d; %lf; %lf; %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao, tempo_ordenar_vetor, tempo_total_busca);
        resultado = jumpSearch(vetorOrdenar,TAM,numerosSorteados[i]);
        //printf("%s %d %d %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        fprintf(arquivo, "%s; %d; %d; %lf; %lf; %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao, tempo_ordenar_vetor, tempo_total_busca);
        resultado = buscaBinaria(vetorOrdenar,numerosSorteados[i],TAM);
        //printf("%s %d %d %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao);
        fprintf(arquivo, "%s; %d; %d; %lf; %lf; %lf\n",nome_busca, resultado, valor_buscado, tempo_execucao, tempo_ordenar_vetor, tempo_total_busca);
    }

    fclose(arquivo);
    return 0;
}
