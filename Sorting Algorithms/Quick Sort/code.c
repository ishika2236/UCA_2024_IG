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
