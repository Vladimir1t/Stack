#include "Stack.h"

FILE* ERROR_FILE = fopen ("errorF.txt", "w");

void StackCtor (struct Stack* stk, const size_t capacity)
{
    if (capacity <= 0)
        fprintf ( ERROR_FILE, "Error. Capacity <= 0\n");
    stk->size = 0;
    stk->capacity = capacity;
    stk->data = (elem_t*) calloc (stk->capacity, sizeof(elem_t));
    if (stk->data == NULL)
        fputs ("ERROR. Calloc", ERROR_FILE);

    for (int i = 0; i < capacity; i++)
        stk->data[i] = POISON;

    Verifier (stk);
}

void StackPush (struct Stack* stk, const elem_t* value)
{
    Verifier (stk);

    if (stk->size == stk->capacity)
        StackReallocIncrease (stk);

    stk->data[stk->size] = *value;
    //printf ("StackPush(): element = %d\n", stP->data[stP->size]);

    stk->size++;

    Verifier (stk);
}

void StackPop (struct Stack* stk, elem_t* element)
{
    Verifier (stk);

    assert (element != NULL);

    if (stk->size == 0)
    {
        printf ("there are no numbers to be popped\n");
        fputs ("<< there are no numbers to be popped >>\n", ERROR_FILE);
    }

    if (stk->size * 4 < stk->capacity)
        StackReallocDecrease (stk);

    *element = stk->data[stk->size - 1];
    stk->data[stk->size - 1] = POISON;
    //printf ("StackPop(): popped number = %d\n", *element);
    stk->size--;

    Verifier (stk);
}

void StackDtor (struct Stack* stk)
{
    Verifier (stk);

    for (size_t i = 0; i < stk->size; i++)
        stk->data[i] = POISON;

    stk->capacity = 0;
    stk->size = 0;

    free (stk->data);

    stk->data = NULL;
}

int StackReallocIncrease (struct Stack* stk)
{
     Verifier (stk);

     elem_t* pointer = stk->data;
     stk->data = (elem_t*) realloc (stk->data, (stk->capacity * 2) * sizeof(elem_t));

     if (stk->data == NULL)
     {
        stk->data = pointer;
        fputs ("<< Realloc increase error >>\n", ERROR_FILE);
        return REALLOC_ERR;
     }
     for (int i = stk->capacity; i < stk->capacity * 2; i++)
        stk->data[i] = POISON;

     stk->capacity *= 2;

     Verifier (stk);

     return REALLOC_OK;
}

int StackReallocDecrease (struct Stack* stk)
{
     Verifier (stk);

     elem_t* pointer = stk->data;
     stk->data = (elem_t*) realloc (stk->data, (stk->capacity / 2) * sizeof(elem_t));
     if (stk->data == NULL)
     {
        stk->data = pointer;
        fputs ("<< Realloc decrease error >>\n", ERROR_FILE);
        return REALLOC_ERR;
     }
     stk->capacity /= 2;

     Verifier (stk);

     return REALLOC_OK;
}

void Dump (struct Stack* stk, FILE* logFile)
{
    Verifier (stk);
    assert (logFile != NULL);

    fputs ("-----------------\n", logFile);
    fputs ("Stack dump\n", logFile);
    fprintf (logFile, "capacity: %d\n", stk->capacity);
    fprintf (logFile, "size: %d\n", stk->size);

    for (int i = 0; i < stk->size; i++)
        fprintf (logFile, "[%d] " SPEC "\n", i, stk->data[i]);
    fputs ("-----------------\n", logFile);

    for (int i = stk->size; i < stk->capacity; i++)
        fprintf (logFile, "[%d] " SPEC "\n", i, stk->data[i]);
    fputs ("-----------------\n", logFile);

    Verifier (stk);
}

void Verifier (struct Stack* stk)
{
    if (stk == NULL)
        fputs ("Error: Stack = NULL\n", ERROR_FILE);

    if (stk->data == NULL)
        fputs ("Error: stk.data = NULL\n", ERROR_FILE);

    if (stk->capacity < stk->size)
        fputs ("Error: capacity < size\n", ERROR_FILE);

    if (stk->capacity < 0)
        fputs ("ERROR: capacity < 0\n", ERROR_FILE);

    if (stk->size <= 0)
        fputs ("ERROR: size <= 0\n", ERROR_FILE);

    for (int i = 0; i < stk->size; i++)
    {
        if (stk->data[i] == POISON)
            fprintf (ERROR_FILE, "element [%d] = POISON value\n", i);
    }
    for (int i = stk->size; i < stk->capacity; i++)
    {
        if (stk->data[i] != POISON)
            fprintf (ERROR_FILE, "element [%d] != POISON value\n", i);
    }
}
