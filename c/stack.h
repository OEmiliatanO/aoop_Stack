#ifndef __STACK_H__
#define __STACK_H__

struct stacknode
{
    struct stacknode *nex, *last;
    int val;
};

struct stack
{
    struct stacknode *now;
    int size;
};

extern void push(struct stack *this, int x);
extern int pop(struct stack *this);
extern struct stack* new_stack();
extern void delete_stack(struct stack *this);

#endif