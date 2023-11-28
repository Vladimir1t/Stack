#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef double elem_t;
const elem_t POISON = -1.0;

struct Stack
{
    size_t  capacity;
    size_t  size;
    elem_t* data;
};

enum ReallocMod
{
    REALLOC_OK  = 1,
    REALLOC_ERR = 0
};

void StackCtor (Stack* stk, const size_t capacity);

void StackPush (Stack* stk, const elem_t* value);

void StackPop  (Stack* stk, elem_t* element);

void StackDtor (Stack* stk);

int StackReallocIncrease (Stack* stk);

int StackReallocDecrease (Stack* stk);

void Verifier (Stack* stk);

#endif // STACK_H_INCLUDED
