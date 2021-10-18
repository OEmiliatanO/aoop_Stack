#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// stack structure contains pointer array where puts data,
// size[] maintains the prefix sum of array size,
// size_ptr represents the maximum position on pointer array that can be used,
// now_size_ptr represents what the position the pointer is now on,
// ptr represents a pointer to a virtual array which's combinded by many arraies.

// return a pointer to stack structure
stack* new_stack()we
{
    stack *tmp = malloc(sizeof(stack));
    if (tmp == NULL) return NULL;

    tmp->ptr = tmp->size_ptr = tmp->now_size_ptr = 0;

    int nodesize_dym = _NODEESIZE_;

    // require memory, if failed require smaller
    do
    {
        if (!nodesize_dym) return NULL;

        tmp->arr[0] = malloc(nodesize_dym * sizeof(int));
        tmp->size[0] = nodesize_dym;
        nodesize_dym >>= 1;

    }while(tmp->arr[0] == NULL);
    
    return tmp;
}

// add a value to this stack
void push(stack *this, int val)
{
    ++this->ptr;
    
    // judge if cross the boundary of the total array space
    if (this->size[this->size_ptr] - 1 < this->ptr)
    {
        ++this->size_ptr;
        if (this->size_ptr >= _MAXN_) return;

        // require memory, if failed require smaller
        int nodesize_dym = _NODEESIZE_;
        do
        {
            if (!nodesize_dym) return;

            this->arr[this->size_ptr] = malloc(nodesize_dym * sizeof(int));
            this->size[this->size_ptr] = nodesize_dym;
            nodesize_dym >>= 1;

        }while(this->arr[this->size_ptr] == NULL);

        this->size[this->size_ptr] += this->size[this->size_ptr - 1]; // maintain the prefix sum of size of arraies 
        this->now_size_ptr = this->size_ptr; // move pointer of size array to maximum position
        this->arr[this->size_ptr][this->ptr - this->size[this->size_ptr - 1]] = val; // push value
    }
    else
    {
        while(this->size[this->now_size_ptr] - 1 < this->ptr) ++this->now_size_ptr;
        this->arr[this->now_size_ptr][this->ptr - (this->now_size_ptr == 0 ? 0 : this->size[this->now_size_ptr - 1])] = val;
    }
}

int pop(stack *this)
{
    // error
    if (this->ptr == 0) return -1;

    int res = this->arr[this->now_size_ptr][this->ptr - (this->now_size_ptr == 0 ? 0 : this->size[this->now_size_ptr - 1])];
    --this->ptr;
    
    // if pointer cross the left boundary of now array
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
