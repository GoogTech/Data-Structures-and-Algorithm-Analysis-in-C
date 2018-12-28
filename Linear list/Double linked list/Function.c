#define _CRT_SECURE_NO_WARNINGS_
#include "Declare.h"
#include <stdio.h>
#include <stdlib.h>
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
/*DETERMINE WHETHER OR NOT THEY ARE EMPTY*/
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
