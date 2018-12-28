#ifndef _SEQSTACH_H_ // ?
#define _SEQSTACH_H_
#define MAXSIZE 1024
#define INFINITY 65535 // ?
/*TIME:18/11/16 THEME:THE ORDER OF THE STACK*/
/*THE DATA OF STACK*/
typedef struct
{
    int data[MAXSIZE];
    int top;
} SeqStack;
/*DECLARE THE FUNCTION*/
/*INITIALIZE THE STACK*/
static void InitStack(SeqStack *stack);
/*DATERMINE IF THE LIST IS EMPTY*/
int IsEmpty(SeqStack *stack);
/*FIND THE HEAD NODE*/
int SeqStack_Top(SeqStack *stack);
/*Pos the top element of the stack*/
int SeqStack_Pop(SeqStack *stack);
/*Push the element into the stack*/
int SeqStack_Push(SeqStack *stack, int node);
/*Destruction of the stack*/
void SeqStack_Destory(SeqStack *stack);

#endif;
