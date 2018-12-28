#include "BinaryTree_Declare.h"
#include <stdio.h>
#include <stdlib.h>

/*Come true the function*/
/*The former sequence traversal(DLR)*/
void preOrder(BinaryTree_Node *T)
{
    if (T == NULL)
        return;
    //Traverse the root node
    printf("%c", T->data);
    //Traverses the left branch
    if (T->lchild != NULL)
    {
        preOrder(T->lchild);
    }
    //Traverses the right branch
    if (T->rchild != NULL)
    {
        preOrder(T->rchild);
    }
}

/* LDR */
void inOrder(BinaryTree_Node *T)
{
    if (T == NULL)
        return;
    //Traverses the left branch
    if (T->lchild != NULL)
    {
        inOrder(T->lchild);
    }
    //Traverse the root node
    printf("%c", T->data);
    //Traverses the right brach
    if (T->rchild != NULL)
    {
        inOrder(T->rchild);
    }
}

/* LRD */
void lastOrder(BinaryTree_Node *T)
{
    if (T == NULL)
        return;
    //Traverse the left branch
    if (T->lchild != NULL)
    {
        lastOrder(T->lchild);
    }
    //Traverses the right branch
    if (T->rchild != NULL)
    {   
        lastOrder(T->rchild);
    }
    //Travers the root node
    printf("%c",T->data);
}