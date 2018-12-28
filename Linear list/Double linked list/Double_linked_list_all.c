// #ifndef _DOUBLE_LINKED_LIST_H_
// #define _DOUBLE_LINKED_LIST_H_
//#include "Declare.h"
#include <stdio.h>
#include <stdlib.h>

//-------------------------------DECLARE---------------------------------------
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
/*CATCH THE EXCEPTION*/
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
//#endif

//-------------------------------FUNCTION---------------------------------------
/*CATCH THE EXCEPTION*/
void HeadNullException(pHead ph)
{
    if (ph == NULL)
        printf("ERROR : THE HEAD NODE IS NULL !\n");
}
/*CREATE A DOUBLE LINKED LIST*/
pHead Create()
{
    pHead ph = (pHead)malloc(sizeof(struct Head));
    HeadNullException(ph);
    ph->length = 0;
    ph->next = NULL;
    return ph;
}
/*RETURN THE LENGTH OF DOUBLE LINKED LIST*/
int getLength(pHead ph)
{
    HeadNullException(ph);
    return ph->length;
}
/*DEMINTER WHETHER OR NOT THEY ARE EMPTY*/
int IsEmpty(pHead ph)
{
    HeadNullException(ph);
    if (ph->length == 0)
        return 1;
    else
        return 0;
}
/*INSERT THE NODE INTO DOUBLE LINKED LIST IN SPECIFIED POSITION*/
int Insert(pHead ph, int position, int value)
{
    pNode p_value = NULL;
    if (ph == NULL || position < 0 || position > ph->length)
        printf("HEAD NODE IS NULL OR IMPROPER INSERTION POSITION !");
    p_value = (pNode)malloc(sizeof(struct Node));
    p_value->data = value;

    //--(っ•̀ω•́)っ✎⁾⁾-- TO DETERMINE THE INSERTION POSITION
    //FIRST DETERMINE WHETHER THE LIST IS EMPTY
    if (IsEmpty(ph))
    {
        ph->next = p_value;
        p_value->next = NULL;
        p_value->previous = NULL;
    }
    else
    {
        pNode pCur = ph->next; //FIRST NODE
        if (position == 0)
        {
            ph->next = p_value;
            p_value->previous = NULL;
            p_value->next = pCur;
            pCur->previous = p_value;
        }
        else
        {
            //LOCATE THE POSITION TO INSERT
            for (int i = 1; i < position; i++)
                pCur = pCur->next;
            //SO SIMPLE SO COOL ~
            p_value->next = pCur->next;
            pCur->next->previous = p_value;
            p_value->previous = pCur;
            pCur->next = p_value;
        }
    }
    ph->length++;
    return 1;
}
/*DELETE NODE FROM DOUBLE LINKED LIST*/
pNode Delete(pHead ph, int value)
{
    if (ph == NULL || ph->length == 0)
        printf("ERROR : NODE HEAD IS NULL OR THE LENGTH OF LIST EQUAL TO ZERO\n");
    //LOCATE THE POSITION TO DELETE
    pNode p_value = Find(ph, value);
    if (p_value == NULL)
        printf("NOT LOCATE THE POSITION TO DELETE\n");

    //printf("DELETE TO SPECIFIED NODE : \n");
    //SO SIMPLE SO COOL ~ ╰(*°▽°*)╯
    pNode pRe = p_value->previous;
    pNode pNext = p_value->next;
    pRe->next = pNext; // ❤ 所删节点的前节点的后节点->所删节点的后一个节点
    pNext->previous = pRe;

    return p_value;
}
/*FIND A NODE FROM DOUBLE LINKED LIST*/
pNode Find(pHead ph, int value)
{
    HeadNullException(ph);
    //LOCATE THE POSITION TO INSERT
    pNode pTemp = ph->next;
    do
    {
        if (pTemp->data == value)
        {
            printf("HAVE FINDED THE SPECIFIED NODE !\n");
            return pTemp;
        }
        pTemp = pTemp->next;
    } while (pTemp->next != NULL);
    printf("HAVEN'T FINDED THE SPECIFIED NODE !\n");
    return NULL;
}
/*DESTORY THE DOUBLE LINKED LIST*/
void Destroy(pHead ph)
{
    pNode pCur = ph->next;
    pNode pTemp;
    HeadNullException(ph);

    //Delete the node of all
    while (pCur->next != NULL)
    {
        pTemp = pCur->next;
        free(pCur);
        pCur = pTemp; //╰(*°▽°*)╯ Exchange data
    }

    //Initializes the header node
    ph->length = 0;
    ph->next = NULL;
}

/*PRINT THE DATA OF NODE OF DOUBLE LINKED LIST OF ALL*/
/*FRONT TO BACK*/
void printFront(pHead ph)
{
    HeadNullException(ph);
    pNode pTemp = ph->next;

    while (pTemp != NULL)
    {
        printf("%d ", pTemp->data);
        pTemp = pTemp->next;
    }
    printf("\n");
}
/*PRINT THE DATA OF NODE OF DOUBLE LINKED LIST OF ALL*/
/*BACK TO FRONT*/
void printBack(pHead ph)
{
    HeadNullException(ph);

    //MOVE TO THE END OF LIST
    pNode pTemp = ph->next;
    while (pTemp->next != NULL)
        pTemp = pTemp->next;

    for (int i = --ph->length; i >= 0; i--)
    {
        printf("%d ", pTemp->data);
        pTemp = pTemp->previous;
    }
    printf("\n");
}

//-------------------------------MAIN---------------------------------------
int main(int argc, char const *argv[])
{
    /*CREATE A DOUBLE LINKED LIST*/
    pHead ph = NULL;
    ph = Create();

    /*INSERT THE NODE INTO DOUBLE LINKED LIST IN SPECIFIED POSITION*/
    int node_data;
    printf("PLEASE ENTER SOME DATA OF NODE : \n");
    while (1)
    {
        scanf("%d", &node_data);
        if (node_data == 0)
            break;
        Insert(ph, 0, node_data);
    }

    /*GET THE LENGTH OF DOUBLE LINKED LIST*/
    printf("--- THE LENGTH OF DOUBLE LINKE LIST ---\n%d\n", getLength(ph));

    /*PRINT(FRONT TO BACK)*/
    printf("\n--- PRINT(FRONT TO BACK) ---\n");
    printFront(ph);
    printf("\n--- PRINT(BACK TO FRONT) ---\n");
    printBack(ph);

    /*INSERT THE NODE INTO DOUBLE LINKED LIST IN SPECIFIED POSITION*/
    int node_insert, node_position;
    printf("--- PLEASE THE NODE YOU WANT TO INSERT ---\n");
    printf("NODE : ");
    scanf("%d", &node_insert);
    printf("POSITION : ");
    scanf("%d", &node_position);
    Insert(ph, node_position, node_insert);
    printf("\n-- (FRONT TO BACK)INSERTED AS RESULT --\n");
    printFront(ph);
    printf("\n");

    // o(╥﹏╥)o ~ NOTICE: scanf("%d"), NOT: scanf("%d ")
    /*FIND A NODE FROM DOUBLE LINKED LIST*/
    int node_find;
    printf("\n--- PLEASE THE NODE OF YOU WANT TO FIND ---\n");
    scanf("%d", &node_find);
    Find(ph, node_find);
    printf("\n");

    /*DELETE NODE FROM DOUBLE LINKED LIST*/
    int node_delete;
    printf("\n--- PLEASE ENTER THE NODE YOU WANT TO DELETE ---\n");
    scanf("%d", &node_delete);
    Delete(ph, node_delete);
    printf("\n-- DELETED AS RESULT --\n");
    printFront(ph);
    printf("\n");

    /*DESTORY THE DOUBLE LINKED LIST*/
    Destroy(ph);
    printf("--- SUCCESS TO DESTORY THE DOUBLE LINKED LIST ---\n");
    printf("THE LENGTH OF DOUBLE LINKED LIST : \n%d\n", ph->length);

    /*CHECK THE EXCEPTION*/
    printf("--- CHECK THE EXCEPTION ---\n");
    ph = ph->next; //ph->next(FIRT NODE)
    HeadNullException(ph);

    system("pause");
    return 0;
}

/*########## RESULT ##########*/
/*

PLEASE ENTER SOME DATA OF NODE :
1 2 3 4 5 6 7 8 9 10 11 1 2 3 4 5 6 7 8 9 10 11 0
--- THE LENGTH OF DOUBLE LINKE LIST ---
22

--- PRINT(FRONT TO BACK) ---
11 10 9 8 7 6 5 4 3 2 1 11 10 9 8 7 6 5 4 3 2 1

--- PRINT(BACK TO FRONT) ---
1 2 3 4 5 6 7 8 9 10 11 1 2 3 4 5 6 7 8 9 10 11
--- PLEASE THE NODE YOU WANT TO INSERT ---
NODE : 111111
POSITION : 11

-- (FRONT TO BACK)INSERTED AS RESULT --
11 10 9 8 7 6 5 4 3 2 1 111111 11 10 9 8 7 6 5 4 3 2 1


--- PLEASE THE NODE OF YOU WANT TO FIND ---
1
HAVE FINDED THE SPECIFIED NODE !


--- PLEASE ENTER THE NODE YOU WANT TO DELETE ---
2
HAVE FINDED THE SPECIFIED NODE !

-- DELETED AS RESULT --
11 10 9 8 7 6 5 4 3 1 111111 11 10 9 8 7 6 5 4 3 2 1       <——————███████~ It's not completely deleted

--- SUCCESS TO DESTORY THE DOUBLE LINKED LIST ---
THE LENGTH OF DOUBLE LINKED LIST :
0

--- CHECK THE EXCEPTION ---
ERROR : THE HEAD NODE IS NULL !

请按任意键继续. . .

*/
