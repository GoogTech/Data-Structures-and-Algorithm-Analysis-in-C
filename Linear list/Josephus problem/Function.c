#include "Declare.h"
#include <stdio.h>
#include <stdlib.h>

/*CATCH THE EXCEPTION OF CIRCULAR LINK*/
void HeadIsNullException(pHead ph)
{
    if (ph == NULL)
        printf("ERROR : THE NODE HEAD IS NULL !\n");
}

/*CATCH THE EXCEPTION OF INPUT*/
void InputIsUnresonable(int input)
{
    if (input < 0)
        printf("ERROR : THE NUMBER THAT YOU ENTERED IS UNREASONABLE !\n");
}

/*CREATE A CIRCULAR LIST*/
pHead Create()
{
    pHead ph = (pHead)malloc(sizeof(struct Head));
    HeadIsNullException(ph);
    ph->length = 0;
    ph->next = NULL;
    return ph;
}

/*DETERMINE WHETHER THE LINK IS EMPTY*/
int IsEmpty(pHead ph)
{
    HeadIsNullException(ph);
    if (ph->length == 0)
        return 1;
    else
        return 0;
}

/*INSERT THE NODE INTO LINK IN SPECIFIED POSITION*/
int Insert(pHead ph, int position, int value)
{
    if (ph == NULL || position < 0 || position > ph->length)
        printf("ERROR : Insertion anomaly !");

    pNode p_value = (pNode)malloc(sizeof(struct Node));
    p_value->data = value;

    //--(っ•̀ω•́)っ✎⁾⁾-- TO DETERMINE THE INSERTION POSITION
    //FIRST DETERMINE WHETHER THE LIST IS EMPTY
    if (IsEmpty(ph))
    {
        ph->next = p_value;
        p_value->next = p_value; //o(*￣︶￣*)o ~ YOU ARE NOT ALONE ..
    }
    else
    {
        //INSERT IN THT FIST POSITION
        pNode p_node = ph->next;
        if (position == 0)
        {
            //FIND THE LAST NODE
            while (p_node->next != ph->next)
                p_node = p_node->next;
            p_value->next = ph->next;
            ph->next = p_value;
            p_node->next = p_value;
        }
        else
        {
            pNode p_node_ = ph->next;
            for (int i = 1; i < position; i++)
                p_node_ = p_node_->next;
            p_value->next = p_node_->next;
            p_node_->next = p_value;
        }
    }
    ph->length++;
    return 1;
}

/*PRINT THE DATA OF NODE OF ALL*/
void print(pHead ph)
{
    if (ph == NULL || ph->length == 0)
        printf("ERROR : THE LENGTH OF LIST IS ZERO !");
    pNode pTemp = ph->next;
    for (int i = 0; i < ph->length; i++)
    {
        printf("%d ", pTemp->data);
        pTemp = pTemp->next;
    }
    printf("\n");
}

/*THE HEART OF ALGORITHM*/
void The_Heart_Of_Algorithm_(pHead ph,int n)
{
    pNode node = ph->next;
    while (node->next != node) //KEEP THE LAST NODE
    {
        for (int i = 1; i < n - 1; i++)
            node = node->next;

        pNode pTemp = node->next;
        //--(っ•̀ω•́)っ✎⁾⁾--DETERMINE THE LOCATION OF NODE
        //First, determine if the position of this node is zero
        if (pTemp == ph->next)
        {
            ph->next = pTemp->next;
            node->next = pTemp->next;
            printf("%d ", pTemp->data);
            free(pTemp);
            ph->length--;
        }
        //Second, the position of this node is others
        else
        {
            node->next = pTemp->next;
            printf("%d ", pTemp->data);
            free(pTemp);
            ph->length--;
        }
        node = node->next;
    }
    node->next = node; //YOU ARE NOT ALONE ~(*^▽^*)~
    printf("\n");
}
