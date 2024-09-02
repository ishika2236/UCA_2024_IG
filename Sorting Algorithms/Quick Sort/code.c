#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quick_sort( int start, int end, int arr[], int pivot_type)
{
  if(start >= end) return;

  int pivot = partition(start, end, arr, pivot_type);
  quick_sort(start, pivot-1, arr, pivot_type);
  quick_sort(pivot + 1, end, arr, pivot_type);
}
int randomPivot(int start, int end)
{
  return start + rand() % (end - start -1);
}
void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp; 
}
int partition (int start, int end, int arr[], int pivot_type)
{
  int pi, i, j;
  switch(pivot_type):
    
    //for middle element
    case 0:
        pi = arr[(start+end)/2];
        break;

    // for first element
    case  1:
        pi = arr[start];
        break;

  //for random element
    case  2:
        pi = arr [randomPivot(start, end)];
        break;

  i = start -1;
  for(int j = low; j <= end; j++)
    {
      if(arr[j] <= pivot)
      {
        i++;
        swap(arr[j], arr[i]);
      }
    }
  return i;
  
}

int main()
{
  int n = 1000;
  int arr[n];
  clock_t start, end;
  double cpu_time_used;

  srand(time(NULL));

  for(int i = 0 ; i < 1000; i++)
    {
      arr[i] = rand() % 1000;
    }
  int arr1[n], arr2[n], arr3[n];
  for(int i = 0 ; i < n; i++)
    {
      arr1[i] = arr[i];
      arr2[i] = arr[i];
      arr3[i] = arr[i];
    }

   // Test pivot as middle element
    start = clock();
    quicksort(arrCopy1, 0, n - 1, 0);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time with middle pivot: %f seconds\n", cpu_time_used);


  // Test pivot as first element
    start = clock();
    quicksort(arrCopy2, 0, n - 1, 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time with first pivot: %f seconds\n", cpu_time_used);

    // Test pivot as random element
    start = clock();
    quicksort(arrCopy3, 0, n - 1, 2);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time with random pivot: %f seconds\n", cpu_time_used);

    return 0;
}
  
