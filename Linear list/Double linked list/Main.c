//#define _CRT_SECURE_NO_WARNINGS_
#include "Declare.h"
#include <stdio.h>
#include <stdlib.h>
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

/*-----------------------------o(╥﹏╥)o----------------------------------

> Executing task: gcc 'e:\Visual Studio Code\Data structures and algorithms\Linear list\Double linked list\Main.c' -o 'e:\Visual Studio Code\Data structures and algorithms\Linear list\Double linked list/Main.exe' -ggdb3 -Wall -std=c11 -Wno-format -finput-charset=UTF-8 -fexec-charset=GBK '-D _USE_MATH_DEFINES' <

C:\Users\ADMINI~1\AppData\Local\Temp\cc0blUt1.o: In function `main':
e:/Visual Studio Code/Data structures and algorithms/Linear list/Double linked list/Main.c:8: undefined reference to `Create'
e:/Visual Studio Code/Data structures and algorithms/Linear list/Double linked list/Main.c:18: undefined reference to `Insert'
e:/Visual Studio Code/Data structures and algorithms/Linear list/Double linked list/Main.c:22: undefined reference to `getLength'
collect2.exe: error: ld returned 1 exit status
The terminal process terminated with exit code: 1

Terminal will be reused by tasks, press any key to close it.

*/

/*############# The solution ################*/
/*
<https://segmentfault.com/a/1190000006049907?utm_source=tag-newest>

(一)通过以下的命令，我们将会得到两个.o文件
PS E:\Visual Studio Code\Data structures and algorithms\Include> gcc -c test.c
PS E:\Visual Studio Code\Data structures and algorithms\Include> gcc -c .\main.c   <———————— 利用'Tab'补全‘main.c’

(二)随后，我们将main.o这个文件，编译成可执行文件
PS E:\Visual Studio Code\Data structures and algorithms\Include> gcc -o main main.o
main.o:main.c:(.text+0x15): undefined reference to `test'   <———————— ERROR : UNDEFINED REFERENCE TO 'XXX'
collect2.exe: error: ld returned 1 exit status

(三)编译时报错了，这是最典型的undefined reference错误，因为在链接时发现找不到某个函数的实现文件。如果按下面这种方式链接就正确了
PS E:\Visual Studio Code\Data structures and algorithms\Include> gcc -o main main.o test.o

(四)(╰(*°▽°*)╯) 当然，也可以按照如下的命令编译，这样就可以一步到位,继而省略(一)(二)(三)
PS E:\Visual Studio Code\Data structures and algorithms\Include> gcc -o main main.c test.c  <———————— 'main' 为可自定义名称

......

*/
