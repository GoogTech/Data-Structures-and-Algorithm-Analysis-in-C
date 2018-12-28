#include "Non-recursive.h"
#include <stdio.h>
#include <stdlib.h>

//Create a stack
LinkStack Create()
{
    LinkStack linkStack = (LinkStack)malloc(sizeof(struct Stack));
    if (linkStack == NULL)
    {
        linkStack->top = NULL;
        linkStack->size = 0;
    }
    return linkStack;
}

//Determines whether the stack is empty.
int IsEmpty(LinkStack linkStack)
{
    if (linkStack->top == NULL || linkStack->size == 0)
    {
        return 1;
    }
    return 0;
}

//Push node into the stack
int Push(LinkStack linkStack, BinaryNode *value)
{
    pNode node = (pNode)malloc(sizeof(struct StackNode));
    if (node != NULL)
    {
        node->data = value;
        node->next = getTop(linkStack);
        linkStack->top = node;
        linkStack->size++;
    }
    return 1;
}

//Get the top of node of Stack
pNode getTop(LinkStack linkStack)
{
    if (linkStack->size != 0)
    {
        return linkStack->top;
    }
    return NULL;
}

//Pop the node from stack
pNode Pop(LinkStack linkStack)
{
    if (IsEmpty(linkStack))
    {
        return NULL;
    }
    pNode node = linkStack->top;
    linkStack->top = linkStack->top->next;
    linkStack->size--;
    return node;
}
