/*
Caio Assunção Albuquerque

Algoritmo MergeSort

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void mergeSort(int *vetor, int ini, int fim)
{
    int mid;
    if(ini < fim)
    {
        mid = floor((ini + fim) / 2);

        //Ordenação das duas metades do vetor
        mergeSort(vetor, ini, mid);
        mergeSort(vetor, mid + 1, fim);

        //Combinamos as duas metades ordenadas
        merge(vetor, ini, mid, fim);
    }
}

void merge(int *vetor, int ini, int mid, int fim)
{
    int *temp,vec1,vec2, tam, i, j, k;
    int fim1 = 0, fim2 = 0;

    tam = fim - ini+1;

    vec1= ini;
    vec2= mid+1;

    temp = (int *) malloc(tam * sizeof(int));

    if(temp!= NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(!fim1 && fim2)
            {
                if(vetor[vec1] < vetor[vec2])
                    temp[i] = vetor[vec1++];
                else
                    temp[i] = vetor[vec2++];

                if(vec1 > mid)
                    fim1 = 1;
                if(vec2 > fim)
                    fim2 = 1;
            }else
            {
                if(!fim1)
                    temp[i] = vetor[vec1++];

                else
                    temp[i] = vetor[vec2++];

            }

        }

        for(j=0, k =ini; j< tam; j++,k++)
        {
            vetor[k]= temp[j];
        }
    }
}


int main()
{

    int NUM = 0;
    int valor = 0;
	char x, y = '\n';

	FILE *leitura;
    leitura = fopen("couting", "r");
    //Contando quantos numeros tem o arquivo txt
    while(fread(&x, sizeof(char),1, leitura)){
	if( x == y)
        {
            NUM++;
        }
    }
	fclose(leitura);

	printf(" %d numeros registrados : \n", NUM+1);

	valor = NUM+1;

    int vetor[valor];

	leitura = fopen("couting", "r");

    for(int i = 0; i<=valor ;i++){
        fscanf(leitura, "%d/n", &vetor[i]);
    }
	fclose(leitura);

	mergeSort(&vetor[0], 0, valor - 1);

	puts("\n Ordenacao concluida com sucesso.\n");
	imprimir(&vetor[0], valor);


	return 0;

}
