#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Stack.h"

int main()
{
    Stack stk = {};
    size_t capacity = 0;

    printf ("write the capacity of a Stack\n");
    scanf  ("%d", &capacity);

    StackCtor (&stk, capacity);

    elem_t value = 0;
    int check = 0;

    while (1)
    {
        printf ("write a number, which you wanted to push. If you want to stop, write -1\n");
        if (scanf ("%lg", &value) != 1)
        {
            printf ("Error\n");
            break;
        }

        if (value == -1)
            break;
        StackPush (&stk, &value);
    }

    elem_t element = POISON;
    StackPop (&stk, &element);

    for (int i = 0; i < stk.size; i++)
        printf ("%d) %lg\n", i, stk.data[i]);

    StackDtor (&stk);

    return 0;
}
