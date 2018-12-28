#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

//-------------------------------------------------
typedef struct Queue *SeqQueue;
/*SEQUENTIAL QUEUE*/
struct Queue
{
    int front;
    int rear;
    int data[MAXSIZE];
};
//-------------------------------------------------


//-------------------------------------------------
/*CREATE A SEQUENTIAL QUEUE*/
SeqQueue Create();
/*GET THE LENGTH OF SEQUENTIAL QUEUE*/
int getLength(SeqQueue Sq);
/*WHETHER IT'S EMPTY*/
int IsEmpty(SeqQueue Sq);
/*INSERT A NODE INTO QUEUE*/
void Insert(SeqQueue Sq, int value);
/*DELETE THE NODE FROM QUEUE*/
int Delete(SeqQueue Sq);
/*GET THE HEAD NODE FROM QUEUE*/
int GetHead(SeqQueue Sq);
/*CLEAR THE SPLACE OF QUEUE*/
void Clear(SeqQueue Sq);
/*DESTORY THE QUEUE*/
void Destory(SeqQueue Sq);
//-------------------------------------------------


//-------------------------------------------------
/*CREATE A SEQUENTIAL QUEUE*/
SeqQueue Create()
{
    SeqQueue Sq = (SeqQueue)malloc(sizeof(struct Queue));
    Sq->front = Sq->rear = -1;
    // ???
    memset(Sq->data, 0, MAXSIZE * sizeof(int));
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
    if (Sq->front == Sq->rear)
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
    if (Sq->rear == Sq->front)
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
//-------------------------------------------------


//-------------------------------------------------
int main()
{
    SeqQueue Sq = Create();
    srand((unsigned)time(0));
    for (int i = 0; i < 10; ++i)
    {
        Insert(Sq, rand() % 100);
    }
    printf("THE LENGTH OF QUEUE :   %d\n", getLength(Sq));
    printf("THE HEAD NODE OF QUEUE :    %d\n", GetHead(Sq));
    printf("--THE DATA OF QUEUE--      --THE OUT OF QUEUE--\n");
    while (Sq->front != Sq->rear)
    {
        int ret = GetHead(Sq);
        printf("%d                                ", ret);
        ret = Delete(Sq);
        printf("%d\n", ret);
    }
    printf("THE LENGTH OF QUEUE :   %d\n", getLength(Sq));
    Clear(Sq);
    Destory(Sq);

    system("pause");
    getchar();
    return 0;
}
