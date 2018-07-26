#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Stack
{
    int top;
    ElemType stack[3];
} Stack, *PStack;

Stack *Stack_create()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

ElemType Stack_push(ElemType elem, Stack *stack)
{
    if (stack->top + 1 == 3)
        return NULL;
    stack->stack[++stack->top] = elem;
    return elem;
}

ElemType Stack_pop(Stack *stack)
{
    if (stack->top < 0)
        return NULL;
    return stack->stack[stack->top--];
}

int main()
{
    Stack *stack = Stack_create();
    ElemType a = Stack_push(0, stack);
    ElemType b = Stack_push(1, stack);
    ElemType c = Stack_push(2, stack);
    ElemType d = Stack_push(3, stack);
    ElemType e = Stack_pop(stack);
    ElemType f = Stack_push(4, stack);
    return 0;
}
