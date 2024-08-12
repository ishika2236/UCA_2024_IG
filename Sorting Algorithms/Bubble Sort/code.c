#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int arr[], int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}

int main()
{

    int start_time,end_time;
    start_time = clock();
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
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++){
            printf("%d ",arr[i]);
    }
    end_time = clock();
    printf("\n time of execution: %f \n",(double)(end_time - start_time) / CLOCKS_PER_SEC);
    return 0;
}
