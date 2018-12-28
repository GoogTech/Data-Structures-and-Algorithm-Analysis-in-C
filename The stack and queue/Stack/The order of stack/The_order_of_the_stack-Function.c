#include "The_order_of_the_stack-Declare.h"
/*TIME:18/11/16 THEME:THE ORDER OF THE STACK*/

/*Initialize the stack*/
void InitStack(SeqStack *stack)
{
    stack->top = -1;
}

/*Datermine if the list is empty*/
int IsEmpty(SeqStack *stack)
{
    if (stack->top == -1)
        return 1;
    else
        return0;
}

/*FINE THE NODE HEAD*/
int SeqStack_Top(SeqStack *stack)
{
    if (!IsEmpty(stack))
        return stack->data[stack->top];
    else
        return INFINITY; // ??
}

/*Pos the top element of the stack*/
int SeqStack_Pop(SeqStack *stack)
{
    if (!IsEmpty(stack))
        return stack->data[stack->top--];
    else
        return INFINITY;
}

/*Push the element into the stack*/
int SeqStack_Push(SeqStack *stack, int node)
{
    if (stack->top >= MAXSIZE - 1)
        return;
    stack->top++;
    stack->data[stack->top] = node;
}

/*Destruction of the stack*/
void SeqStack_Destory(SeqStack *stack)
{
    if (!IsEmpty(stack))
        free(stack);
}