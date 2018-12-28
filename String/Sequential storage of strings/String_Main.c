//#define _CRT_SECURE_NO_WARNINGS
//#include "E:\Visual Studio Code\Data structures and algorithms\String\String_Declare.h"
//#include <E:\Visual Studio Code\Data structures and algorithms\String\String_Declare.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // WHAT ?

int main(int argc, char const *argv[])
{
    String s;
    char arr[1024];
    printf("PLEASE INPUT THE DATA OF STRING :\n");
    scanf("%s", arr);
    strAssign(&s, arr);
    printf("--- THE STRING OF S --- \n");
    print(&s);
    printf("--- THE LENGTH OF S --- %d\n", strLength(&s));

    system("pause");
    getchar();
    return 0;
}
