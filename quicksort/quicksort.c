
/* 

Caio Assunção Albuquerque

Algoritmo QuickSort

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int particiona(int *V, int inicio, int fim){

	int pivo, direita, esquerda, aux;
	esquerda = inicio;
	direita = fim;
	pivo = V[inicio];

	while(esquerda<direita){

		while(V[esquerda] <= pivo){
			esquerda++;
		}
		while(V[direita] > pivo){
			direita--;
		}
		if(esquerda < direita){
			aux = V[esquerda];
			V[esquerda] = V[direita];
			V[direita] = aux;
		}
	}
	V[inicio] = V[direita];
	V[direita] = pivo;
	return direita;

}
void quickSort(int *V, int inicio, int fim){
	
	int pivo;
	if(fim > inicio){

		pivo = particiona(V,inicio,fim);
		quickSort(V,inicio,pivo-1);
		quickSort(V,pivo+1,fim);
	}
}


void imprimir(int V[], int tam)
{
    int i;
    FILE *leitura;
    leitura = fopen("couting.txt", "w");
	for (i = 0; i < tam; i++) {
    fprintf (leitura,"%d \n",V[i]);
    }
    fclose(leitura);
}

int  main()
{
	
}
