// main.c
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    test();
    system("pause");
    return 0;
}
/*############# UNDEFINED REFERENCE TO 'XXX' ################*/
/*
> Executing task: gcc 'e:\Visual Studio Code\Data structures and algorithms\Include\main.c' -o 'e:\Visual Studio Code\Data structures and algorithms\Include/main.exe' -ggdb3 -Wall -std=c11 -Wno-format -finput-charset=UTF-8 -fexec-charset=GBK '-D _USE_MATH_DEFINES' <

C:\Users\ADMINI~1\AppData\Local\Temp\ccsh55dN.o: In function `main':
e:/Visual Studio Code/Data structures and algorithms/Include/main.c:6: undefined reference to `test'
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

/*############ TO RUN THE PROGRAM ##############*/
//<https://blog.csdn.net/qq_28581077/article/details/81380341>

/*
Microsoft Windows [版本 10.0.17134.407]
(c) 2018 Microsoft Corporation。保留所有权利。

E:\Visual Studio Code\Data structures and algorithms>cd Include     
E:\Visual Studio Code\Data structures and algorithms\Include>gcc -o Main main.c test.c  <———————— 'gcc -o Main main.c test.c'
E:\Visual Studio Code\Data structures and algorithms\Include>Main.exe   <———————— 'Main.exe'(The program running !)
just test it
请按任意键继续. . .
*/
