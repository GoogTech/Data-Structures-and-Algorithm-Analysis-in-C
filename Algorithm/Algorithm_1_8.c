#include <stdio.h>
#define N 10 //由于数组大小不确定,所以采用宏定义的方式,数组大小改变时只需改变N对应的值继而不需要改动程序
/*
    冒泡排序
    Time：18/10/14
*/
int main()
{
    int i, j, a[N], t;
    printf("PLEASE INPUT THE NUMBERS :\n");
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < N - 1; i++)         //这里改写成：for(i=0;i<N;i++) 就很好理解了
    {
        for (j = 0; j < N - i; j++)     // ❤ 注意：N-i 与 a[j]>a[j+1] 之间的约束关系
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("THE NUMBER OF SURE :\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    getchar();
    return 0;
}

/*
    问题扩展：
    排序可以大概分为：冒泡,选择,插入,快速,堆排序..
    这里简单再介绍一下选择排序(最坏情况下需要比较次数为：n(n-1)/2)
*/
int main()
{
    int s[N], i, j, k, t;
    printf("The original data : \n");
    for (i = 0; i < N; i++)
        scanf("4%d\n", &s[i]);
    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++)
            if (s[j] > s[i])
            {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
    printf("The data after sorted :\n");
    for (i = 0; i < N; i++)
        printf("%4d\n", s[i]);
    getchar();
    return 0;
}