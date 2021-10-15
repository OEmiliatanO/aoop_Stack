#include <stdlib.h>
#include "stack.h"

void push(struct stack *this, int x)
{
    if (this->size == 0)
    {
        this->now = (struct stacknode *)malloc(sizeof(struct stacknode));
        if (this->now == NULL)
        {
            return;
        }
        ++this->size;
        this->now->last = this->now->nex = NULL;
        this->now->val = x;
        return;
    }

    this->now->nex = (struct stacknode *)malloc(sizeof(struct stacknode));
    if (this->now->nex == NULL)
    {
        return;
    }
    ++this->size;
    this->now->nex->last = this->now;
    this->now = this->now->nex;
    this->now->nex = NULL;
    this->now->val = x;

    return;
}

int pop(struct stack *this)
{
    if (this->size == 0) return 0;

    int res = this->now->val;
    if (this->now->last)
    {
        this->now = this->now->last;
        free(this->now->nex);
        --this->size;
        this->now->nex = NULL;

        return res;
    }

    free(this->now);
    --this->size;
    this->now = NULL;

    return res;
}

struct stack* new_stack()
{
    struct stack* p = (struct stack*)malloc(sizeof(struct stack));
    p->size = 0;
    p->now = NULL;
    return p;
}

void delete_stack(struct stack* this)
{
    while(this->size) pop(this);
    free(this);
    this = NULL;
}