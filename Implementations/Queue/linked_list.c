#include "code.h"

struct Node
{
    int item;
    struct Node* next;
};
typedef struct Node Node;

int N = 0;
Node* tail = NULL;
Node* head =  NULL;

int size()
{
    return N;
}

bool isEmpty()
{
    return N == 0;
}

void push(int item)
{
    Node* oldtail = tail;
    tail = (Node*) malloc(sizeof(Node));
    tail -> item = item;
    tail -> next = NULL;

    if(isEmpty()) head = tail;
    else oldtail -> next =  tail;
    N++;
}

int pop()
{
    if(isEmpty()) return INT_MIN;
    int item = head -> item;
    Node* temp = head;
    head= head -> next;
    if(isEmpty()) tail = NULL;
    N--;
    free(temp);
    return item;
}

void testQueue()
{
    push(3);
    push(10);
    push(19);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(pop() == 3);
    assert(size() == 2);
    assert(pop() == 10);
    assert(size() == 1);
    assert(pop() == 19);free(head);
    free(tail);
    assert(size() == 0);
    assert(isEmpty() == true);

    
}


int main()
{
     testQueue();
    printf("All tests passed. \n");
    return 0;

}


