#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

int main()
{
    SeqQueue Sq = Create();
    srand((unsigned)time(0));
    for (int i = 0; i < 10; ++i)
    {
        Insert(Sq, rand() % 100);
    }
    printf("THE LENGTH OF QUEUE :   %d", getLength(Sq));
    printf("THE HEAD NODE OF QUEUE      THE OUT OF QUEUE\n");
    while (Sq->front != Sq->rear)
    {
        int ret = GetHead(Sq);
        printf("%d      ", ret);
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
