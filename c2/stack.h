#ifndef __STACK_H__
#define __STACK_H__


#define _MAXN_ 1000
#define _NODEESIZE_ 100000

typedef struct stack
{
    int *arr[_NODEESIZE_];
    int size[_MAXN_];
    int size_ptr;
    int now_size_ptr;
    int ptr;
}stack;

extern void push(stack *this, int x);
extern int pop(stack *this);
extern stack* new_stack();
extern void delete_stack(stack *this);

#endif