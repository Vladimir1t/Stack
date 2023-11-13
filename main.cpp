#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "StructStack.h"
#include "StackCtor.h"
#include "StackPush.h"
#include "StackPop.h"
#include "StackDtor.h"

int main()
{
    Stack st = {};
    int capacity = 0;

    printf ("write the capacity of a Stack\n");
    scanf  ("%d", &capacity);

    StackCtor (&st, capacity);

    int numberPush = 0;

    while (numberPush != -1)
    {
        printf ("write a number, which you wanted to push\n");
        while (scanf  ("%d", &numberPush) != 1)
            printf ("try again");

        StackPush (&st, numberPush);
    }
    for (int i = 0; i < st.size; i++)
        printf ("%d) %d\n", i, st.data[i]);

    int element = StackPop (&st);

    for (int i = 0; i < st.size; i++)
        printf ("%d) %d\n", i, st.data[i]);

    StackDtor (&st);

    return 0;
}
