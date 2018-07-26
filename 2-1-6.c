#include <stdio.h>

typedef struct Node
{
    Node *next;
    int data;
} Node, *PNode;

int list_length(PNode pnode)
{
    int i = 0;
    while (pnode)
    {
        i++;
        pnode = pnode->next;
    }
    return i;
}

PNode list_findbyindex(int p, PNode pnode)
{
    int i = 0;
    while (pnode && i < p)
    {
        pnode = pnode->next;
        i++;
    }
    if (i == p)
        return pnode;
    else
        return NULL;
}

PNode list_findbyvalue(int v, PNode pnode)
{
    while (pnode)
    {
        if (pnode->data == v)
            return pnode;
        pnode = pnode->next;
    }
    return NULL;
}

PNode list_insert(int data, int i, PNode pnode)
{
    PNode s, p;
    if (i == 0)
    {
        s = (PNode)malloc(sizeof(Node));
        s->data = data;
        s->next = pnode;
        return s;
    }
    p = list_findbyindex(i, pnode);
    if (!s)
    {
        return NULL;
    }
    s = (PNode)malloc(sizeof(Node));
    s->next = p->next;
    p->next = s;
    s->data = data;
    return pnode;
}

PNode list_delete(int i, PNode pnode)
{
    PNode t, s;
    if (i == 0)
    {
        if (!pnode) {
            return NULL;
        }
        t = pnode;
        pnode = pnode->next;
        free(t);
        return pnode;
    }
    t = list_findbyindex(i, pnode);
    if (!pnode) return NULL;
    s = t->next;
    t->next = s->next;
    free(s);
    return pnode;
}

int main()
{

    return 0;
}