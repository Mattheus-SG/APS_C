#include <stdio.h>
#include <time.h>
#define tamanho 5000
int vet[tamanho];

void criarVetor(){ 
    FILE *arquivoNum;
    arquivoNum=fopen("num5000CDA.txt", "r");
	int i;
    for(i=0; i<tamanho; i++){
        fscanf(arquivoNum, "%d", &vet[i]);
    }
    fclose(arquivoNum);
}

void insertionSort(int vetor[], int n)
{
	int i, chave, j;
	for (i = 1; i < n; i++) {
		chave = vetor[i];
		j = i - 1;
		while (j >= 0 && vetor[j] > chave) {
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = chave;
	}
}


void bubbleSort(int vetor[], int tam) {
	int troca, i;
  for (troca = 0; troca < tamanho - 1; ++troca) {
    for (i = 0; i < tamanho - troca - 1; ++i) {
      if (vetor[i] > vetor[i + 1]) {
        int temp = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = temp;
      }
    }
  }
}

int main()
{
  criarVetor();
  
	int i;
    for(i = 0; i < tamanho; i++){
        printf("%d,  ", vet[i]);
    }
    printf("\n");

  clock_t t;
	t = clock();
	bubbleSort(vet, tamanho);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("A função levou %f secondos para executar! \n", time_taken);
}
