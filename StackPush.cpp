#include "StackPush.h"

void StackPush (struct Stack* stP, const int numberPush)
{
    if (stP->size == stP->capacity)
    {
        stP->data = (int*) realloc (stP->data, (stP->size * 2) * sizeof(int));
        stP->capacity *= 2;
    }

    stP->data[stP->size] = numberPush;
    printf ("StackPush(): element = %d\n", stP->data[stP->size]);

    stP->size++;

    printf ("StackPush(): number has been pushed successfully\n");
}
