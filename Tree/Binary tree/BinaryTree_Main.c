#include "BinaryTree_Declare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
THEME :Traverses the binary tree
TIME : December 5,2018 17:26
*/
int main(int argc, char const *argv[])
{
    //Create six of node of binary tree
    BinaryTree_Node nodeA,nodeB,nodeD,nodeF,nodeI,nodeL;

    //Initialize these nodes
    memset(&nodeA,0,sizeof(BinaryTree_Node));
    memset(&nodeB,0,sizeof(BinaryTree_Node));
    memset(&nodeD,0,sizeof(BinaryTree_Node));
    memset(&nodeF,0,sizeof(BinaryTree_Node));
    memset(&nodeI,0,sizeof(BinaryTree_Node));
    memset(&nodeL,0,sizeof(BinaryTree_Node));
    nodeA.data = 'A';
    nodeB.data = 'B';
    nodeD.data = 'D';
    nodeF.data = 'F';
    nodeI.data = 'I';
    nodeL.data = 'L';
    //Store the logical relationships between nodes
    nodeA.lchild = &nodeB;
    nodeA.rchild = &nodeD;
    nodeB.rchild = &nodeF;
    nodeF.lchild = &nodeL;
    nodeD.lchild = &nodeI;
    printf("Success to create a binary tree !\n");

    //DLR
    printf("\nDLR : ");
    preOrder(&nodeA);
    //LDR
    printf("\nLDR : ");
    inOrder(&nodeA);
    //LRD
    printf("\nLRD : ");
    lastOrder(&nodeA);

    printf("\n");
    system("pause");//Need add the 'include <stdlib.h>'
    return 0;
}

//E:\Visual Studio Code\Data structures and algorithms\Tree\Binary tree>gcc -o Binary_tree BinaryTree_Function.c BinaryTree_Main.c

/*
Success to create a binary tree !

DLR : ABFLDI
LDR : BLFAID
LRD : LFBIDA
请按任意键继续. . .

*/

