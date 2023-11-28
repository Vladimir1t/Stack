#include "Stack.h"

void StackPush (Stack* stk, const elem_t* value);
void StackPop  (Stack* stk, elem_t* element);
void StackDtor (Stack* stk);
int StackReallocIncrease (Stack* stk);
int StackReallocDecrease (Stack* stk);
void Verifier (Stack* stk);

void StackCtor (Stack* stk, const size_t capacity)
{
    assert (capacity >= 0);

    stk->size = 0;
    stk->capacity = capacity;
    stk->data = (elem_t*) calloc (stk->capacity, sizeof(elem_t));

    for (int i = 0; i < capacity; i++)
        stk->data[i] = POISON;
    //printf ("Stack is constructed\n");

    Verifier (stk);
}

void StackPush (Stack* stk, const elem_t* value)
{
    Verifier (stk);

    if (stk->size == stk->capacity)
        StackReallocIncrease (stk);

    stk->data[stk->size] = *value;
    //printf ("StackPush(): element = %d\n", stP->data[stP->size]);

    stk->size++;
    //printf ("StackPush(): number has been pushed successfully\n");
}

void StackPop (Stack* stk, elem_t* element)
{
    Verifier (stk);

    assert (element != NULL);

    if (stk->size == 0)
        printf ("there are no numbers to be popped\n");

    if (stk->size * 4 < stk->capacity)
        StackReallocDecrease (stk);

    *element = stk->data[stk->size - 1];
    stk->data[stk->size - 1] = 0;
    //printf ("StackPop(): popped number = %d\n", *element);
    stk->size--;

    Verifier (stk);
}

void StackDtor (Stack* stk)
{
    Verifier (stk);

    for (size_t i = 0; i < stk->size; i++)
        stk->data[i] = POISON;

    stk->capacity = 0;
    stk->size = 0;

    free (stk->data);

    stk->data = NULL;

    //printf ("Stack has been destructed\n");
}

int StackReallocIncrease (Stack* stk)
{
     Verifier (stk);

     elem_t* pointer = stk->data;
     stk->data = (elem_t*) realloc (stk->data, (stk->capacity / 2) * sizeof(elem_t));

     if (stk->data == NULL)
     {
        stk->data = pointer;
        printf ("Realloc increase error\n");
        return REALLOC_ERR;
     }
     for (int i = stk->capacity; i < stk->capacity * 2; i++)
        stk->data[i] = POISON;

     stk->capacity *= 2;
     return REALLOC_OK;
}

int StackReallocDecrease (Stack* stk)
{
     Verifier (stk);

     elem_t* pointer = stk->data;
     stk->data = (elem_t*) realloc (stk->data, (stk->capacity / 2) * sizeof(elem_t));
     if (stk->data == NULL)
     {
        stk->data = pointer;
        printf ("Realloc decrease error\n");
        return REALLOC_ERR;
     }
     stk->capacity /= 2;

     return REALLOC_OK;
}

void Dump ()
{

}

void Verifier (Stack* stk)
{
    assert (stk           != NULL);
    assert (stk->data     != NULL);

    assert (stk->capacity >= stk->size);
    assert (stk->capacity > 0);
    assert (stk->size >= 0);

    for (int i = 0; i < stk->size; i++)
        assert (stk->data[i] != POISON);
}
