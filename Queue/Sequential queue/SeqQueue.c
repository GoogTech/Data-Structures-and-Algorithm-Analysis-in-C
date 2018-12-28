#include "SeqQueue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*CREATE A SEQUENTIAL QUEUE*/
SeqQueue Create()
{
    SeqQueue Sq = (SeqQueue)malloc(sizeof(struct Queue));
    Sq->front = Sq->rear = -1;
    // ???
    memset(Sq->rear, 0, MAXSIZE * sizeof(int));
    return Sq;
}
/*GET THE LENGTH OF QUEUE*/
int getLength(SeqQueue Sq)
{
    return Sq->rear - Sq->front;
}
/*WHETHER IT'S EMPTY*/
int IsEmpty(SeqQueue Sq)
{
    if (Sq->front = Sq->rear)
        return 1;
    else
        return 0;
}
/*INSERT A NODE INTO QUEUE*/
void Insert(SeqQueue Sq, int value)
{
    //If the length of sequential queue is max
    if (Sq->rear == MAXSIZE - 1)
    {
        printf("THE LENGTH OF QUEUE IS MAX ~\n");
        return;
    }
    //If the sequential queue is empty
    if (Sq->front == Sq->rear)
    {
        Sq->front = Sq->rear = 0;
        Sq->data[Sq->rear] = value;
        Sq->rear++;
    }
    else
    {
        Sq->data[Sq->rear] = value;
        Sq->rear++;
    }
}
/*DELETE THE NODE FROM QUEUE*/
int Delete(SeqQueue Sq)
{
    //If the sequential queue is empty
    if (Sq->rear == Sq->front)
    {
        printf("THE SEQUENTIAL QUEUE IS EMPTY ~\n");
        return 666666;
    }
    int temp = Sq->data[Sq->front];
    Sq->front++; // ...
    return temp;
}
/*GET THE HEAD NODE FROM THE QUEUE*/
int GetHead(SeqQueue Sq)
{
    //If the sequential queue is empty
    if (sq->rear == Sq->front)
    {
        printf("THE SEQUENTIAL QUEUE IS EMPTY ~\n");
        return 66666;
    }
    return Sq->data[Sq->front];
}
/*CLEAR THE SPLACE OF SEQUENTIAL QUEUE*/
void Clear(SeqQueue Sq)
{
    Sq->front = Sq->rear = -1;
    printf("HAVE CLEARED THE SPLACE OF SEQUENTIAL QUEUE\n");
}
/*DESTORY THE SEQUENTIAL QUEUE*/
void Destory(SeqQueue Sq)
{
    free(Sq);
    printf("SUCCESS OF DESTORYING !\n");
}

