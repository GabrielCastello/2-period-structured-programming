/* 12) Considere um vetor com 15 números inteiros lidos pelo teclado. Faça um algoritmo
para imprimir este vetor em ordem não-decrescente utilizado o algoritmo QuickSort.
Utilize três procedimentos: um para preencher o vetor, outro para ordenar o vetor e um
terceiro para imprimir o vetor antes e depois da ordenação. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Data
{
  int numbers[15];
};

void setArrayData(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
  {
    if (i != 0)
      printf("\n-----------------------------------\n");
    printf("Digite o %iº número: ", i + 1);
    scanf("%i", &arr[i]);
  }
}

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    /* pi is partitioning index, arr[p] is now 
           at right place */
    int pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printNumbers(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    printf("%i ", arr[i]);
}

int main()
{
  srand(time(NULL));

  struct Data numbers;

  setArrayData(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nAntes da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\n");
  int n = sizeof(numbers.numbers) / sizeof(numbers.numbers[0]);
  quickSort(numbers.numbers, 0, n - 1);
  // insertionSort(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nDepois da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));

  printf("\n\n");
  return 0;
}