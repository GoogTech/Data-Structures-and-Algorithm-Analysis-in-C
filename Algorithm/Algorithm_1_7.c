#include <stdio.h>
/*
    假设银行一年整存的月利息为：0.63%.现在某人手中有一笔钱,他打算在今后的五年中每年年底取出一千元
    到第五年时刚好全部取出.问：存存钱时应出入多少 ?
    Time:18/10/14
*/

//算法设计：从第五年初开始向前递推就可求出这个人应该在银行中存钱的钱数.
int main()
{
    int i;
    double money = 0.0;
    for (i = 5; i >=1; i--)
        money = (money + 1000.0) / (1 + 12 * 0.0063);
    printf("MONEY = %0.2f\n", money);         //结果保留两位小数
    getchar();
    return 0;
}
//result : MONEY = 4039.44