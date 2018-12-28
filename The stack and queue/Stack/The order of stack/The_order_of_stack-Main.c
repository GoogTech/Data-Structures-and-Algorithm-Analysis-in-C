#include <stdio.h>
#include <stdlib.h>
#include "The_order_of_the_stack-Declare.h"
/*TIME:18/11/16 THEME:THE ORDER OF THE STACK*/
int main(int argc, char const *argv[])
{
    //CREATE A RANDOM
    srand((unsigned)time(0));

    /*Initialize the stack*/
    SeqStack stack;
    InitStack(&stack);

    /*ADD NODE INTO LIST*/
    for (int i = 0; i < 10; i++)
        SeqStack_Push(&stack, rand() % 1000);

    /*GET ALL NODES FROM THE LIST*/
    printf("HEAD NODE : %d\n", SeqStack_Top(&stack));

    /*PRINT ALL NODES FROM THE LIST*/
    printf("ALL NODES : ");
    for (int i = 0; i < 10; i++)
        printf("%d", SeqStack_Pop(&stack));

    // ???
    system("pause");
    return 0;
}
