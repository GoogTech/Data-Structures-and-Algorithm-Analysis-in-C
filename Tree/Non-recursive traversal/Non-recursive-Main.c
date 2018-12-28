#include "Non-recursive.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Find the starting node of traversed tree
BinaryNode *GoFarLeft(BinaryNode *T, LinkStack linkStack)
{
    if (T == NULL)
    {
        return NULL;
    }
    while (T->lchild != NULL)
    {
        Push(linkStack, T);
        T = T->lchild;
    }
    return T;
}

//Non-recursive traversal (LDR)
void Non_recursive_LDR(BinaryNode *T)
{
    LinkStack linkStack = Create();
    //Find the starting node of traversed tree
    BinaryNode *binaryNode = GoFarLeft(T, linkStack);

    while (binaryNode != NULL)
    {
        printf("%c", binaryNode->data);
        //If a node has a right subtree, it accesses the right subtree.
        if (T->rchild != NULL)
        {
            T = GoFarLeft(binaryNode->rchild, linkStack);
        }
        else if (!IsEmpty(linkStack))
        {
            //Returns the top of stack element node.
            binaryNode = getTop(linkStack)->data;
            //Pop the top element of the stack
            Pop(linkStack);
        }
        else
        {
            binaryNode = NULL;
        }
    }
}

//Test the program
int main(int argc, char const *argv[])
{
    //Create six node
    BinaryNode nodeA, nodeB, nodeD, nodeF, nodeI, nodeL;

    //Initialize all node of tree
    memset(&nodeA, 0, sizeof(BinaryNode));
    memset(&nodeB, 0, sizeof(BinaryNode));
    memset(&nodeD, 0, sizeof(BinaryNode));
    memset(&nodeF, 0, sizeof(BinaryNode));
    memset(&nodeI, 0, sizeof(BinaryNode));
    memset(&nodeL, 0, sizeof(BinaryNode));

    //Assign values to nodes.
    nodeA.data = 'A';
    nodeB.data = 'B';
    nodeD.data = 'D';
    nodeF.data = 'F';
    nodeI.data = 'I';
    nodeL.data = 'L';

    //Store the logical relationships between nodes.
    nodeA.lchild=&nodeB;
    nodeA.rchild=&nodeD;
    nodeB.rchild=&nodeF;
    nodeF.lchild=&nodeL;
    nodeD.lchild=&nodeI;

    printf("Success to create a binary tree ! Non-recursive traversal (LDR)\n");
    Non_recursive_LDR(&nodeA);
    printf("\n");

    system("pause");
    return 0;
}

/*

E:\Visual Studio Code\Data structures and algorithms\Tree\Non-recursive traversal>gcc -o Result Non-recursive-Function.c Non-recursive-Main.c
Non-recursive-Function.c: In function 'Push':
Non-recursive-Function.c:30:18: warning: initialization from incompatible pointer type [-Wincompatible-pointer-types]
     pNode node = (LinkStack)malloc(sizeof(struct StackNode));
                  ^
C:\Users\ADMINI~1\AppData\Local\Temp\ccL4HI4e.o:Non-recursive-Main.c:(.text+0xbc): undefined reference to `IsEmpty'
collect2.exe: error: ld returned 1 exit status

*/