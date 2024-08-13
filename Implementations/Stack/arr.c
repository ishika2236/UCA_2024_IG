#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
#include "implementation.h"

int * arr;
int N;
int max_size;

bool isEmpty()
{
    return N == 0;
}

int size()
{
    return N;
}

void resize(int new_size)
{
    int* new_arr = (int *) malloc(new_size * sizeof(int));
    for(int i = 0; i < N; i++)
    {
        new_arr[i] = arr[i];
    }
    free(arr);
    arr = new_arr;
    max_size = new_size;
}

void push(int num)
{
    if(arr  == NULL)
    {
        arr = (int *) malloc(max_size * sizeof(int));
    }
    else if(max_size == N)
    {
        resize( 2 * max_size);
    }
    arr[N++] = num;
}

int pop()
{
    if(isEmpty())return INT_MIN;
    int item = arr[--N];
    if(N == max_size/4)
    {
        resize(max_size / 2);
    }
    return item;
}

void testCase()
{
    push(3);
    push(10);
    push(19);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(pop() == 19);
    assert(size() == 2);
    assert(pop() == 10);
    assert(size() == 1);
    assert(pop() == 3);
    assert(size() == 0);
    assert(isEmpty());

    free(arr);
}

int main()
{
    testCase();
    printf("All test cases ran smoothly \n");
    return 0;
}
