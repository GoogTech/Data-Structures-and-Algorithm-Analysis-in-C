#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

/*DEFINE THE TYPE OF STRUCT*/
typedef struct Head *pHead;
typedef struct Node *pNode;

//DEFINE THE HEAD NODE
struct Head
{
    int length;
    pNode next;
};
//DEFINE THE DATA NODE
struct Node
{
    int data;
    pNode previous;
    pNode next;
};
/*DECLARE THE FUNCTION*/
void HeadNullException(pHead ph);
/*CREATE A DOUBLE LINKED LIST*/
pHead Create();
/*RETURN THE LENGTH OF DOUBLE LINKED LIST*/
int getLength(pHead ph);
/*DEMINTER WHETHER OR NOT THEY ARE EMPTY*/
int IsEmpty(pHead ph);
/*INSERT THE NODE INTO DOUBLE LINKED LIST IN SPECIFIED POSITION*/
int Insert(pHead ph, int position, int value);
/*DELETE NODE FROM DOUBLE LINKED LIST*/
pNode Delete(pHead ph, int value);
/*FIND A NODE FROM DOUBLE LINKED LIST*/
pNode Find(pHead ph, int value);
/*DESTORY THE DOUBLE LINKED LIST*/
void Destroy(pHead ph);
/*PRINT(FRONT TO BACK)*/
void printFront(pHead ph);
/*PRINT(BACK TO FRONT)*/
void printBack(pHead ph);
#endif
