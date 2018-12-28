#include<stdio.h>
/*
    18/10/13
    共有五本书,要借给A,B,C这三位小盆友,没人只能借一本,问：共有多少种借法 ?
    此算法的运算次数为：time=125
*/

int main()
{
    int a,b,c,times,count=0;
        for(a=1;a<=5;a++)
        {
            for(b=1;b<=5;b++)
            {
                for(c=1;c<=5;c++)
                {   times++;
                    if(a!=b&&b!=c&&a!=c)
                    {
                        printf("A:%d,B:%d,C:%d\n",a,b,c);
                            count++;
                            if(count%4==0)printf("\n");
                    }
                }
            }
        }
        printf("count:%d\n",count);
        printf("times:%d\n",times);     //查看'穷举法'算法所查看的次数
        getchar();
    return 0;
}


/*
    问题扩展：由题目要求而知：如果前两个人所选书号相同,那么无论第三个人所选的书号与前两人相同与否都是无效的借阅方法
    而对于上述程序中的第三层循环来说不管a,b的取值是否相同,循环都要重复进行五次！
    所以需要在进行第三次for循环前先判断a,b的值,如果两者取值相同,内层循环无须重复执行五次便可结束.

    (对于数据量大的问题,此做法效率的提高更加明显!此算法运算次数：times=100)
*/

/*
int main()
{
    int a,b,c,times,count=0;
        for(a=1;a<=5;a++)
        {
            for(b=1;b<=5;b++)
            {
                for(c=1;c<=5&&a!=b;c++)           //增加判断：a!=b
                {   times++;
                    if(a!=b&&b!=c&&a!=c)
                    {
                        printf("A:%d,B:%d,C:%d\n",a,b,c);
                            count++;
                            if(count%4==0)printf("\n");
                    }
                }
            }
        }
        printf("count:%d\n",count);
        printf("times:%d\n",times);     //查看'穷举法'算法所查看的次数
        getchar();
    return 0;
}
*/

