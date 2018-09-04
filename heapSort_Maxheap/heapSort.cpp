// Caio Assunção Albuquerque

// Heap Sort

#include <iostream>

using namespace std;

// Para obter uma subárvore com raiz no nó "i" que é um índice em arr[]  ( n é o tamanho do heap)
void heapify(int array[], int n, int i)
{
	int largest = i; // Inicialize o maior como raiz
	int l = 2*i + 1; // esq = 2*i + 1
	int r = 2*i + 2; // dir = 2*i + 2

	// Para filho esq maior que a raiz
	if (l < n && array[l] > array[largest])
		largest = l;

	// Para filho dir ser maior que o maior até o momento
	if (r < n && array[r] > array[largest])
		largest = r;

	// Se maior não for raiz
	if (largest != i)
	{
		swap(array[i], array[largest]);

	// Faz recursivamente o heapify, para a subárvore
		heapify(array, n, largest);
	}
}

// função que faz o heap sort
void heapSort(int array[], int n)
{
	// Construir heap (reorganizar array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i);

	// Extrai elementos da heap um por um
	for (int i=n-1; i>=0; i--)
	{
		// Move a raiz atual para o final
		swap(array[0], array[i]);

		// chama max heapify no heap reduzido
		heapify(array, i, 0);
	}
}

/* Uma função p/ imprimir o tamanho de n */
void printArray(int arr[], int n)
{
	for (int i=0; i<n; ++i)
		cout << array[i] << " " << endl;
}

int main()
{
	int array[] = {20, 11, 5, 13, 6, 8};
	int n = sizeof(array)/sizeof(array[0]);

	heapSort(array, n);

	cout << "O array ordenado eh: \n";
	printArray(array, n);

	return 0;
}