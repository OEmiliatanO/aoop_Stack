#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*
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
*/
stack* new_stack()
{
    stack *tmp = calloc(1, sizeof(stack));
    if (tmp == NULL) return NULL;

    tmp->ptr = tmp->size_ptr = tmp->now_size_ptr = 0;

    int nodesize_dym = _NODEESIZE_;

    do
    {
        if (!nodesize_dym) return NULL;

        tmp->arr[0] = calloc(nodesize_dym, sizeof(int));
        tmp->size[0] = nodesize_dym;
        nodesize_dym >>= 1;

    }while(tmp->arr[0] == NULL);
    
    return tmp;
}

void push(stack *this, int val)
{
    ++this->ptr;
    if (this->size[this->size_ptr] - 1 < this->ptr)
    {
        ++this->size_ptr;
        if (this->size_ptr >= _MAXN_) return;

        int nodesize_dym = _NODEESIZE_;
        do
        {
            if (!nodesize_dym) return;

            this->arr[this->size_ptr] = calloc(nodesize_dym, sizeof(int));
            this->size[this->size_ptr] = nodesize_dym;
            nodesize_dym >>= 1;

        }while(this->arr[this->size_ptr] == NULL);

        this->size[this->size_ptr] += this->size[this->size_ptr - 1];
        this->now_size_ptr = this->size_ptr;
        this->arr[this->size_ptr][this->ptr - this->size[this->size_ptr - 1]] = val;
    }
    else
    {
        while(this->size[this->now_size_ptr] - 1 < this->ptr) ++this->now_size_ptr;
        this->arr[this->now_size_ptr][this->ptr - (this->now_size_ptr == 0 ? 0 : this->size[this->now_size_ptr - 1])] = val;
    }
}

int pop(stack *this)
{
    if (this->ptr == 0) return -1;

    int res = this->arr[this->now_size_ptr][this->ptr - (this->now_size_ptr == 0 ? 0 : this->size[this->now_size_ptr - 1])];
    --this->ptr;
    if (this->now_size_ptr > 0 && this->ptr - this->size[this->now_size_ptr - 1] < 0)
        --this->now_size_ptr;

    return res;
}

void delete_stack(stack *this)
{
    for (int i = 0; i <= this->size_ptr; ++i)
    {
        free(this->arr[i]);
        this->arr[i] = NULL;
    }

    free(this);
}