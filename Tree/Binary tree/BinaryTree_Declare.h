#ifndef _Binary_tree_
#define _Binary_tree_

//Defind a binary tree
typedef struct BinaryTree_Node
{
    char data;
    struct BinaryTree_Node *lchild,*rchild;

}BinaryTree_Node;

//Declare function
//DLR
void preOrder(BinaryTree_Node *T);
//LDR
void inOrder(BinaryTree_Node *T);
//LRD
void lastOrder(BinaryTree_Node *T);
    
#endif //_Binary_tree_

