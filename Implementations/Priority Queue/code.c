#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct priorityQueue
{
    int* arr;
    int n;
    int capacity;
};

void exch(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp; 
}

void initQ(struct priorityQueue* q, int capacity)
{
    q->arr = (int*) calloc(capacity + 1, sizeof(int));
    q->capacity = capacity;
    q->n = 0;
}

int size(struct priorityQueue* q)
{
    return q->n;
}

void swim(struct priorityQueue* q, int k)
{
    int *arr = q->arr;
    while (k > 1 && arr[k] > arr[k/2]) 
    {
        exch(arr, k, k/2);
        k = k / 2;
    }
}

void insert(struct priorityQueue* q, int x)
{
    if (q->n == q->capacity) {
        printf("Queue is full!\n");
        return;
    }
    q->arr[++(q->n)] = x;
    swim(q, q->n);
}

bool isEmpty(struct priorityQueue* q)
{
    return q->n == 0;
}

int top(struct priorityQueue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[1];
}

void sink(struct priorityQueue* q, int k)
{
    int n = q->n;
    int* arr = q->arr;
    while (2*k <= n)
    {
        int j = 2*k;
        if (j < n && arr[j] < arr[j + 1]) j++;
        if (arr[k] >= arr[j]) break;
        exch(arr, k, j);
        k = j;
    }
}

void pop(struct priorityQueue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    exch(q->arr, 1, q->n);
    q->n--;
    sink(q, 1);
}

int main()
{
    struct priorityQueue* pq = (struct priorityQueue*) malloc(sizeof(struct priorityQueue));
    int size;
    printf("Enter capacity of queue: \n");
    scanf("%d", &size);
    initQ(pq, size);

    insert(pq, 10);
    assert(top(pq) == 10);

    insert(pq, 1);

    insert(pq, 19);

    insert(pq, 1);

    insert(pq, 45);

    insert(pq, 13);

    insert(pq, 12);
    assert(top(pq) == 45);

    while (!isEmpty(pq)) {
        int currentTop = top(pq);
        pop(pq);
        if (!isEmpty(pq)) {
            assert(currentTop >= top(pq)); 
        }
    }

    free(pq->arr);
    free(pq);
    return 0;
}

//note ptrs
// utility data structure
//just a collection

// how to implement priority queue

// problem solving scenarios : fenwick tree ( binary indexed trees)

// if k is an index in an array then 2k and 2k + 1 are its children //conceptual.. alaways dealing with baanced  binary tree

// if k is an index then k/2 will  be its parent

// max priority queue wil be opposite of min priority queue
// a parent can never be smaller than its child, it can be equal but can never be smaller

// since this is a perfect binary tree height will be equal to logn
// for n insertions complexity will be n log n

// sink operation in delete
