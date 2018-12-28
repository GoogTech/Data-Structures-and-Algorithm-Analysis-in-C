#include <stdio.h>
#include <stdlib.h>

/*
Author : #YUbuntu
Description : Create the binary tree using the # sign method
Date : December 19,2018
*/

//Definde the struct of binary tree
typedef struct BitNode
{
    char data;
    struct BitNode *lchild, *rchild;
} BitNode;

//inorder traversing
static void inOrder(BitNode *T)
{
    if (T == NULL)
    {
        return;
    }
    //The left branch of the tree
    if (T->lchild != NULL)
    {
        inOrder(T->lchild);
    }
    //The root node of tree
    printf("%c", T->data);
    //The right brance of the tree
    if (T->rchild != NULL)
    {
        inOrder(T->rchild);
    }
}

//Create the binary tree using the # sign method
BitNode *BitNode_Create()
{
    BitNode *temp = NULL;
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        temp = NULL;
        return temp;
    }
    else
    {
        temp = (BitNode *)malloc(sizeof(BitNode));
        if (temp == NULL)
        {
            return NULL;
        }
        temp->data = ch;
        temp->lchild = NULL;
        temp->rchild = NULL;

        //Create the left and right subtrees of the root node.
        temp->lchild = BitNode_Create();
        temp->rchild = BitNode_Create();
        return temp;
    }
}

//Release the binary tree
static void BitNode_Free(BitNode *T)
{
    if (T == NULL)
    {
        return;
    }
    //Release the reource of left branch of the tree
    if (T->lchild != NULL)
    {
        BitNode_Free(T->lchild);
        T->lchild = NULL;
    }
    //Release the resource of right branch of the tree
    if (T->rchild != NULL)
    {
        BitNode_Free(T->rchild);
        T->rchild = NULL;
    }
    //Realase the root node of binary tree last.
    free(T);
}

//Test the program
int main(int argc, char const *argv[])
{
    BitNode *T = NULL;
    printf("Please enter the element value of binary tree : \n");

    //Create the binary tree firstly
    T = BitNode_Create();

    //Inorder traversing
    printf("The result as inordering traversing as follow :\n");
    inOrder(T);
    printf("\n");

    //Release the source of the binary tree
    BitNode_Free(T);
    printf("Have released the source of the binary tree ! \n");

    //stady the console
    system("pause");
    return 0;
}
