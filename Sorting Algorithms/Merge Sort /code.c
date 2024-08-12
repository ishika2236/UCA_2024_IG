include<stdlib.h>
#include<stdio.h>

void merge(int * aux, int arr[], int left, int mid, int right)
{
        for(int i = left; i <= right; i++) aux[i] = arr[i];

        int i = left;
        int j = mid + 1;

        for(int k = left;k <= right; k++)
        {
                if(i > mid) arr[k] = aux[j++];
                else if(j > right) arr[k] = aux[i++];
                else if(aux[i] <= aux[j]) arr[k] = aux[i++];
                else arr[k] = aux[j++];
        }
}


void mergesort_r(int* aux, int arr[], int left, int right)
{
        if(left >= right) return;

        int mid = (left + right) / 2;
        mergesort_r(aux, arr, left, mid);
        mergesort_r(aux, arr, mid+1, right);
        merge(aux, arr, left, mid, right);

}

void mergeSort(int arr[], int n)
{
        int* aux =  (int *) malloc(n * sizeof(int));

        mergesort_r(aux,arr,0,n-1);
        free(aux);
}

int main()
{
        int n;
        printf("Enter size of array: \n");
        scanf("%d", &n);
        
        int arr[n];
        printf("Enter elements of array\n");
        for(int i = 0; i < n; i++)
        {
                int ele;
                scanf("%d",&arr[i]);
        }
        mergeSort(arr, n);
        for(int i = 0; i < n; i++){
                printf("%d ",arr[i]);
        }

}
