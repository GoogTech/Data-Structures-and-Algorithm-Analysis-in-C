#ifndef _SEQUENTIAL_QUEUE_H
#define _SEQUENTIAL_QUEUE_H
#define MAXSIZE 50

typedef struct Queue *SeqQueue;
/*SEQUENTIAL QUEUE*/
struct Queue
{
    int front;
    int rear;
    int data[MAXSIZE];
};

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

#endif
