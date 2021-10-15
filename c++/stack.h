#ifndef __STACK_H__
#define __STACK_H__

struct stacknode
{
    stacknode *nex, *last;
    int val;
    stacknode(int value): val(value) { last = nex = nullptr; };
};

class Stack
{
    int size;
    stacknode* now;

    public:

    void push(int);
    int pop();
    int Size();
    Stack();
    ~Stack();
};

#endif