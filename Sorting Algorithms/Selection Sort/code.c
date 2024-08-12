#include<stdio.h>
#include<assert.h>
#include<time.h>


void exch(int arr[], int i, int min){
    int temp = arr[i];

    arr[i] = arr[min];
    arr[min] = temp;

}


void selection_sort(int  arr[], int n){
    for(int i = 0; i < n; i++){
        int min=i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        exch(arr, i, min);
    }
}

void test_simple_input(){

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time=clock();
    
    int arr[] = {3, 1, 7, 9, 5};
    int expected_output[] = {1, 3, 5, 7, 9};

    selection_sort(arr,5);

    for(int i = 0; i < 5; i++){
        // printf("%d\n", arr[i]);
        assert(arr[i] == expected_output[i]);
    }

    end_time=clock();

    cpu_time_used=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("%f\n", cpu_time_used);

}

void test_simple_input2(){

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time=clock();
    
    int arr[] = {10, 34, 23, 21, 12, 112, 1, 32, 43, 10};
    int expected_output[] = {1, 10, 10, 12, 21, 23, 32, 34, 43, 112};

    selection_sort(arr,10);

    for(int i = 0; i < 10; i++){
        // printf("%d\n", arr[i]);
        assert(arr[i] == expected_output[i]);
    }

    end_time=clock();

    cpu_time_used=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("%f\n", cpu_time_used);

}

int main(){
    
    test_simple_input();
    test_simple_input2();
   

    return 0;
}
