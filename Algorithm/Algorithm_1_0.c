#include <stdio.h>
//【证明算法的美 ！】计算1——>100的和

//普通思维算法,运算次数COUNT=100
/*
int main()
{
    int i, sum, count;
    for (i = 1; i <= 100; i++)
    {
        count++;  
        sum += i;
    }
    printf("SUM = %d\n", sum);
    printf("COUNT = %d\n", count);
    getchar();
    return 0;
}
*/

//简洁思维算法,运算次数为COUNT=1
int main()
{
    int sum;
    int count=0;
    int n=100;
    sum = (1 + n) * n / 2;
    printf("SUM = %d\n", sum);
    printf("COUNT = %d\n", ++count);
    getchar();
    return 0;
}