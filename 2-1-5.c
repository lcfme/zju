#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct Array
{
    int last;
    int data[MAXSIZE];
} Arr;

Arr *array_create()
{
    Arr *Parr;
    int i;
    Parr = (Arr *)(malloc(sizeof(Arr)));
    for (i = 0; i < MAXSIZE; ++i)
    {
        Parr->data[i] = i;
    }
    Parr->last = i;
    return Parr;
}

int array_find(int v, Arr *Parr)
{
    int i = 0;
    while (i <= Parr->last)
    {
        if (Parr->data[i] == v)
        {
            return i;
        }
        ++i;
    }
    return -1;
}

int array_insert(int v, int p, Arr *Parr)
{
    int i;
    if (Parr->last == MAXSIZE - 1)
        return 0;
    if (p < 1 || p > Parr->last + 2)
        return 0;
    for (i = Parr->last; i >= p - 1; --i)
        Parr->data[i + 1] = Parr->data[i];
    Parr->data[i + 1] = v;
    Parr->last++;
    return 1;
}

int array_delete(int p, Arr *Parr)
{
    int i;
    if (p < 1 || p > Parr->last + 1)
        return 0;
    for (i = p - 1; i < Parr->last; ++i)
    {
        Parr->data[i] = Parr->data[i + 1];
    }
    Parr->last--;
    return 1;
}

int main()
{
    Arr *parr = array_create();
    array_insert(1, 1, parr);
    int p = array_find(9, parr);
    array_delete(4, parr);
    return 0;
}
