#include <stdio.h>
/*
    中国有句俗话说'三天打鱼两天晒网'.
    题目：某人从1990/1/1日起开始'三天打鱼两天晒网',问这个人在以后某一天是'打鱼'还是'晒网'
    Programming Time:18/10/13
*/

//定义日期结构体(好吧,暂时还没接触学习这种语法)
typedef struct date
{
    int year;
    int month;
    int day;
} DATE;

//函数声明(这样写也可以哟)
int countDay(DATE);
int runYear(int);

//程序入口
void main()
{
    DATE today;   //指定的日期
    int totalDay; //指定日期距离1990/1/1的天数
    int result;   //判断打鱼还是筛网

    printf("please input the DATE: include Year,month,day :\n");
    scanf("%d%d%d", &today.year, &today.month, &today.day);

    //求出指定日期距离1990/1/1日的天数
    totalDay = countDay(today);
    result = totalDay % 5;
    if (result > 0 && result < 4)
        printf("Let's to catch some fishes ~\n");
    else
        printf("I need a sunnet.So let's have a rest ~\n");
    printf("%d\n", getchar());        //很尴尬..使用这个连个函数的不同表达形式来暂停Console ...
getchar();
}

//判断是否为闰年
int runYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

//计算指定日期距离1990/1/1日的天数
int countDay(DATE currentDay)
{
    int perMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int totalDay = 0, year, i;
    for (year = 1990; year < currentDay.year; year++)
    {
        if (runYear(year))
            totalDay = totalDay + 366;
        else
            totalDay = totalDay + 365;
    }
    if (runYear(currentDay.year))               //如果是闰年,则二月份为二十九天
        perMonth[2]++;

    for (i = 0; i < currentDay.month; i++)      //将本年内的天数累加到totalDay中
        totalDay += perMonth[i];

    totalDay += currentDay.day;                 //将本月的天数累加到totalDay中
    return totalDay;
}