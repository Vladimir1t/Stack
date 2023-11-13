#include "StackPop.h"

int StackPop (struct Stack* stP)
{
    if (stP->size == 0)
    {
        printf ("there are no numbers to be popped\n");
        return 0;
    }
    if (stP->size < stP->capacity)
    {
        stP->data = (int*) realloc (stP->data, (stP->capacity / 2) * sizeof (int));
    }

    int element = stP->data[stP->size - 1];
    stP->data[stP->size - 1] = 0;
    printf ("StackPop(): popped number = %d\n", element);
    stP->size--;

    return element;
}