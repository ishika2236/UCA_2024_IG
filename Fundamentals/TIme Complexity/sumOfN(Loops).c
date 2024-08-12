//using time.h library
#include<stdio.h>
#include<time.h>

int main(){
    clock_t start_time,end_time;
    double cpu_time_used;


    start_time=clock();
    int sum=0;
    // int n;
    
    for(int i=0;i<1000000;i++){
        sum+=i;
    }
    // printf("%d",sum);
    end_time=clock();

    cpu_time_used=((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("%f",cpu_time_used);
    return 0;
}
