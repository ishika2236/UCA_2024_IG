#include <stdbool.h> // by default c doesn't support bool values..it uses 0 and 1 to define false/true..we can use true and false by using this header file

void push(int item);
int pop();
int size();
bool isEmpty();

//disassociate interface from implementation


