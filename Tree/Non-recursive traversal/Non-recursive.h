#ifndef _Binary_Tree_H
#define _Binary_Tree_H

/**
 * Title : The binary tree.
 * Description : Non-recursive traversal of binary trees.
 * Author : #YUbuntu
 * Time : December 10,2018
 */

//The structure node of binary tree
typedef struct BinaryNode
{
    char data;
    struct BinaryNode *lchild, *rchild;
} BinaryNode;

//The node structure of the stack
typedef struct StackNode *pNode;
typedef struct Stack *LinkStack;

struct StackNode
{
    BinaryNode *data;
    pNode next;
};

struct Stack
{
    pNode top;
    int size;
};

//Declare the function

//Create a stack
LinkStack Create();
//Determines whether the stack is empty
int IsEmpty(LinkStack linkStack);
//Push node into the stack
int Push(LinkStack linkStack, BinaryNode *value);
//Get the top node of Stack
pNode getTop(LinkStack linkStack);
//Pop the node from stack
pNode Pop(LinkStack LinkStack);

#endif