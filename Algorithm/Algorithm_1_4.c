#include <stdio.h>
/*
    问题描述：
        一辆卡车违反交通规则,现场有三人目击该事件,但都没有记住车号,但记下了车号的一些特征：
        甲说：牌号的后两位数字是相同的
        乙说：牌号的后两位数字是相同的但与前两位不同
        丙说：四位车牌号刚好是一个整数的平方
    请根据上述信息求出该车牌号 ?
*/
/*
    问题扩展(改善算法)：
        在最里层中if里加break;之前：
            THE GUEST OF K IS:7744
            THE RUN OF COUNTS IS :6120

        在最里层中if里加break;之后：
            THE GUEST OF K IS:7744
            THE RUN OF COUNTS IS :6109
        
        控制循环for();使用flag后：
            THE GUEST OF K IS:7744
            THE RUN OF COUNTS IS :4613
*/
void main()
{
    int i, j, k, tmep, count, flag;
    //bool flag = false; //判断K是否已找到,找到后立即结束所有循环(下式无法访问该布尔值 ???)
    for (i = 0; i <= 9; i++)
    {
        if (flag)
            break;
        for (j = 0; j <= 9; j++)
        {
            if (flag)
                break;
            if (i != j)
            {
                k = 1000 * i + 100 * i + 10 * j + j;
                for (tmep = 32; tmep <= 99; tmep++)
                {
                    count++;
                    if (tmep * tmep == k)
                    {
                        printf("THE GUEST OF K IS:%d\n", k);
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
    printf("THE RUN OF COUNTS IS :%d\n", count);
    getchar();
}
