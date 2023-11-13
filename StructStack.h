#ifndef STRUCTSTACK_H_INCLUDED
#define STRUCTSTACK_H_INCLUDED

struct Stack
{
    size_t capacity;
    size_t size;
    int*   data;
};

#endif // STRUCTSTACK_H_INCLUDED
