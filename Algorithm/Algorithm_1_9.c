#include <stdio.h>
#define N 10

/*
    折半查找法
    Time:18/10/14
    BUG:1,13无法查找其索引值
*/
int main()
{
    int i, a[N] = {3, 6, 2, 8, 9, 4, 1, 33, 13, 53}, low = 0, high = N - 1, mid, k = -1, m;
    printf("a'datas of numbers :\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("please input that you need the index of data :\n");
    scanf("%d", &m);

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (m < a[mid])
            high = mid - 1;
        else if (m > a[mid])
            low = mid + 1;
        else
        {
            k = mid;
            break;
        }
    }
    if (k >= 0)
        printf("The data of you had inputed is :%d\nThe index of data is :%d\n", m,k);
    else
        printf("Sorry I don't had find that the index of data ..OR No have it..\n");
    printf("%d\n", getchar());      //e ... 可是是应为这个才导致上述BUG ..
    getchar();
    return 0;
}