#include "stack.h"

void Stack::push(int x)
{
    if (size == 0)
    {
        now = new stacknode(x);
        ++size;

        return;
    }

    now->nex = new stacknode(x);
    now->nex->last = now;
    now = now->nex;
    ++size;

    return;
}

int Stack::pop()
{
    if (size == 0) return 0;

    int res = now->val;

    --size;
    if (now->last)
    {
        now = now->last;
        delete now->nex;
        now->nex = nullptr;
    }
    else
    {
        delete now;
        now = nullptr;
    }
    
    return res;
}

int Stack::Size()
{
    return size;
}

Stack::Stack()
{
    size = 0, now = nullptr;
}

Stack::~Stack()
{
    while (size) pop();
    now = nullptr;
}
