#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*TIME-18/11/24/9:18*/

/*DECLARE THE FUNCTION*/
int find(char *s, char *t);

/*DEFINE THE FUNCTION-PLAIN PATTERN MATCHING*/
int find(char *s, char *t)
{
    int i = 0, j = 0;

    while (i < strlen(s) && j < strlen(t))
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else //RESTART
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == strlen(t))       //SUCCESS
        return i - strlen(t); // ❤ ╰(*°▽°*)╯ ? !
    else
        return -1;
}

/*TEST*/
int main(int argc, char const *argv[])
{
    char s[1024], t[1024];
    printf("(S)STRING : \n");
    scanf("%s", s);
    printf("(T)STRING : \n");
    scanf("%s", t);
    printf("\n");

    printf("THE LENGTH OF STRING OF S : \n%d\n", strlen(s));
    printf("THE LENGTH OF STRING OF T : \n%d\n", strlen(t));

    int result = find(s, t);
    if (result == -1)
        printf("FAIL TO STRING PATTERN MATCHING");
    else
        printf("SUCCESS TO STRING PATTERN MATCHING!THE POSITION : %d\n", result);
    printf("\n");

    system("pause"); //(*^▽^*) REPLACE THE 'getchar()' ~
    return 0;
}
