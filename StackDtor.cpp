#include "StackDtor.h"

void StackDtor (struct Stack* stP)
{
    stP->capacity = 0;

    for (size_t i = 0; i < stP->size; i++)
        stP->data[i] = 0;

    stP->size = 0;

    free (stP->data);

    stP->data = NULL;

    printf ("Stack has been destructed\n");
}
