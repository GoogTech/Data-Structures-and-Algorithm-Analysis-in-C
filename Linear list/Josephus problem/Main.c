#include "Declare.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    int m, n;
    /*INITIALIZED DATA*/
    printf("Please enter the total number of peoples of Josphus problem :\n");
    scanf("%d", &m);
    InputIsUnresonable(m);

    printf("Please enter the index of node that you want to delete :\n");
    scanf("%d", &n);
    InputIsUnresonable(n);

    /*CREATE A CRICULAR LIST*/
    pHead ph = NULL; //<—————————— 'INITIALIZED THE CIRCULAR LINK'
    ph = Create();
    HeadIsNullException(ph);
    for (int i = m; i > 0; i--)
        Insert(ph, 0, i);
    printf("\n");
    printf("--- THE DATA OF ALL NODE OF  YOU INSERT ---\n");
    print(ph);

    /*--- THE HEART OF ALGORITHM ---*/
    printf("--- out put the order of the loop list ---\n");
    The_Heart_Of_Algorithm_(ph, n);

    /*FINAL RESULT*/
    printf("--- THE LAST OF NODE ---\n");
    print(ph);

    system("pause");
    return 0;
}

/*################# TO RUN THE PROGRAM #######################*/

//<https://blog.csdn.net/qq_28581077/article/details/81380341>

/*
Microsoft Windows [版本 10.0.17134.407]
(c) 2018 Microsoft Corporation。保留所有权利。

E:\Visual Studio Code\Data structures and algorithms>cd "Linear list\Josephus problem"

E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem>gcc -o Main Main.c Function.c     <———————— (Compiles the c file into an executable binary)

E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem>Main.exe      <———————— 'Main.exe'(Program running)
Please enter the total number of peoples of Josphus problem :
8
Please enter the index of node that you want to delete :
3

--- THE DATA OF ALL NODE OF  YOU INSERT ---
1 2 3 4 5 6 7 8
--- out put the order of the loop list ---
3 6 1 5 2 8 4
--- THE LAST OF NODE ---
7
请按任意键继续. . .
*/

//###### OR #########
/*
Microsoft Windows [版本 10.0.17134.407]
(c) 2018 Microsoft Corporation。保留所有权利。

E:\Visual Studio Code\Data structures and algorithms>cd "Linear list\Josephus problem"

E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem>gcc -g Main.c -o Main.exe     <———————— ██████ERROR : undefined reference to 'xxx' ❤ The solution : <https://segmentfault.com/a/1190000006049907?utm_source=tag-newest>
C:\Users\ADMINI~1\AppData\Local\Temp\ccwmR351.o: In function `main':
E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem/Main.c:21: undefined reference to `Create'
E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem/Main.c:22: undefined reference to `HeadIsNullException'
E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem/Main.c:24: undefined reference to `Insert'
E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem/Main.c:27: undefined reference to `print'
E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem/Main.c:63: undefined reference to `print'
collect2.exe: error: ld returned 1 exit status

E:\Visual Studio Code\Data structures and algorithms\Linear list\Josephus problem>gcc -g Main.c Function.c -o Main.exe

// E:\Visual Studio Code\Data structures and lgorithms\Linear list\Josephus problem>Main.exe
Please enter the total number of peoples of Josphus problem :
8
Please enter the index of node that you want to delete :
3
--- THE DATA OF ALL NODE OF  YOU INSERT ---
1 2 3 4 5 6 7 8
--- out put the order of the loop list ---
3 6 1 5 2 8 4
--- THE LAST OF NODE ---
7
请按任意键继续. . .
*/