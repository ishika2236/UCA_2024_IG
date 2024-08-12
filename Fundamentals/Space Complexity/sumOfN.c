
#include<stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(){
    struct rusage usage_start;

    getrusage(RUSAGE_SELF, &usage_start);

    int *arr=(int* )malloc(100000*sizeof(int));

    struct rusage usage_end;

    getrusage(RUSAGE_SELF,&usage_end);

    // Calculate memory usage in kilobytes
    long memory_used = usage_end.ru_maxrss - usage_start.ru_maxrss;
    printf("%ld",memory_used);


    
    
}
