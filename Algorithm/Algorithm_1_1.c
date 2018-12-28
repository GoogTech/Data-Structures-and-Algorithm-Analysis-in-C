#include <stdio.h>
/*
18/10/13
中国古代数学家张丘建在他的<算经>中提出了一个著名的'百钱百鸡问题'：
一只公鸡值五钱,一只母鸡值三千,三只小鸡值一钱,现在要用百钱买百鸡,请问公鸡,母鸡,小鸡各多少只 ?
*/

int main()
{
    int cock, hen, chicken,count;
    for (cock = 0; cock <= 20; cock++)
    {
        for (hen = 0; hen <= 33; hen++)
        {
            for (chicken = 0; chicken <= 100; chicken++)
            {   
                count++;
                if ((5 * cock + 3 * hen + chicken / 3.0 == 100) && (cock + hen + chicken == 100))
                    printf("cock=%d,hen=%d,chicken=%d\n", cock, hen, chicken);
            }
        }
    }
    printf("count=%d\n",count);
    getchar();
    return 0;
}

/*
  采用'穷举法'需要穷举尝试21*34*101=72114次(算法的效率显然太低)
  对于本题而言：公鸡的数量确定后，小鸡的数量就固定为：100-cock-hen,继而无需再进行穷举法.(此时约束条件只有一个：5*cock+3*hen+chicken/3.0==100)
  这样可以利用双重循环即可实现：(此算法只需要尝试：21*34=714次,相比上述算法运算减少了十倍左右)
*/

/*
int main()
{
    int cock,hen,chicken,count;
        for(cock=0;cock<=20;cock++)
        {
            for(hen=0;hen<=33;hen++)
            {
                count ++;
                chicken=100-cock-hen;
                    if(5*cock+3*hen+chicken/3.0==100)
                        printf("cock=%d,hen=%d,chicken=%d\n",cock,hen,chicken);
            }
        }
    printf("count=%d\n",count);
    getchar();
    return 0;
}
*/