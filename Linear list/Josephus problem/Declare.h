#ifndef _Josephus_problem_
#define _Josephus_problem_

/*Simplify the code*/
typedef struct Head *pHead;
typedef struct Node *pNode;

/*Define the header node*/
struct Head
{
    int length;
    pNode next;
};
/*Define data nodes*/
struct Node
{
    int data;
    pNode next;
};

/*DECLARE THE FUNCTION*/
/*CATCH THE EXCETPION*/
void HeadIsNullException(pHead ph);
/*CATCH THE EXCEPTION OF INPUT*/
void InputIsUnresonable(int input);
/*CREATE A CRICULAR LIST*/
pHead Create();
/*DETERMINE WHETHER THE LINK IS EMPTY*/
int IsEmpty(pHead ph);
/*INSET THE NODE INTO LINKE IN SPECIFIED POSITION*/
int Insert(pHead ph, int position, int value);
/*PRINT THE DATA OF NODE OF ALL*/
void print(pHead ph);
/*THE HEART OF ALGORITHM*/
void The_Heart_Of_Algorithm_(pHead ph, int n);

#endif