#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "implementation.h"

struct Node
{
    int item;
    struct Node* next;
};

typedef struct Node Node;
Node* head = NULL;
int N = 0;

void push (int item) //runtime complexity: for one operations : O(1) ..For N operations : O(N)
{
    Node* oldhead = head;
    head = (Node *) malloc(sizeof(Node));
    head->item = item;
    head->next = oldhead;
    N++;
}

int pop() // runtime complexity for N operations: O(N)
{
    if(N==0) return INT_MIN;
    int item = head -> item;
    Node* temp = head;
    head = head->next;
    N--;
    free(temp);
    return item;
}

int size() // runtime complexity for N operations: O(N)
{
    return N;
}
bool isEmpty() // runtime complexity for N operations: O(N)
{
    return N==0;
}
void testStack()
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
}
int main()
{
    testStack();
    return 0;
}
// in c and cpp..size of int is different in different implementations can be 4 bytes in laptop, 8 bytes in super computers etc (not actual data, just for reference);
