#include "StackCtor.h"

void StackCtor (struct Stack* stP, const int capacity)
{
    stP->capacity = capacity;
    stP->data = (int*) calloc (stP->capacity, sizeof(int));

    printf ("Stack is constructed\n");
}
