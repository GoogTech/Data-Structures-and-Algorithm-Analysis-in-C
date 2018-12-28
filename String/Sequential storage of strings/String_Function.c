#include "String_Declare.h"
#include "String/String_Declare.h"
#include <stdlib.h>
#include <stdio.h>
/*THEME:STRING-FUNCTION TIME:18/11/23/12:30*/

/*DEFIND TO STRING*/
void strAssign(String *s, char *p)
{
    int i = 0;
    while (p[i] != '\0')
        i++;
    s->string = (char *)malloc((i + 1) * sizeof(char));
    int j = 0;
    for (j = 0; j <= i; j++)
        s->string[j] = p[j];
    s->string[j + 1] = '\0';
    s->length = i; //expect '\0'
}
/*GET THE LENGTH OF STRING*/
int strLength(String *s)
{
    return s->length;
}
/*COPY THE STRING OF T TO S*/
void strCopy(String *s, String *t)
{
    s->string = (char *)malloc((t->length) * sizeof(char));
    memset(s->string, '\0', t->length + 1);
    for (int i = 0; i <= t->length; i++)
        s->string[i] = t->string[i];
}
/*WHETHER IT'S EQUAL*/
int strEqual(String *s, String *t)
{
    if (s->length == t->length)
    {
        while (*(s->string++) != *(t->string))
        {
            printf("NOT EQUAL !\n");
            return 0;
        }
        printf("IT'S EQUAL ~\n");
        return 1;
    }
    printf("NOT EQUAL !\n");
    return 0;
}
/*CONNECT THE STRING OF S AND T*/
void strConnect(String *s, String *t)
{
    int len = s->length + t->length;
    char *temp = (char *)malloc((s->length + t->length) * sizeof(char));
    memset(temp, '\0', s->length);
    int i, j;
    for (i = 0; i < s->length; i++)
        temp[i] = s->string[i];
    for (j = 0; j < t->length; j++, i++)
        temp[i] = s->string[j];
    temp[i] = '\0';
    s->string = temp;
    s->length = s->length * t->length;
}
/*COMPETE THE SIZE OF S AND T*/
int strCompete(String *s, String *t)
{
    if (s && t)
    {
        int s1 = s->length, t1 = t->length;
        while (*(s->string) != '\0' && *(t->string) != '\0')
        {
            if (*(s->string) < *(t->string))
                return -1;
            if (*(s->string) > *(t->string))
                return 1;
            if (*(s->string) == *(t->string))
            {
                s->string++;
                t->string++;
            }
            s->string++;
            t->string++;
        }
        /*THINKING*/
        if (s1 < t1)
            return -1;
        if (s1 == t1)
            return 0;
        if (s1 > t1)
            return 1;
    }
}
/*INSERT THE STRING*/
void Insert(String *s, int position, char *p)
{
    if (position < 0 || position > s->length)
        return;
    int p_length = 0;
    while (p[p_length] != '\0')
        p_length++;
    char *temp = (char *)malloc((p_length + s->length) * sizeof(char));
    int i;
    //front
    for (int i = 0; i < position; i++)
        temp[i] = s->string[i];
    int j;
    //middle
    while (p[j] != '\0')
    {
        temp[i] = p[j];
        i++, j++;
    }
    //rear-end
    for (; position < s->length; position++)
    {
        temp[i] = s->string[position];
        i++; // SO SIMPLE
    }
    temp[i] = '\0';
    s->string = temp;
    s->length = s->length + p_length;
    printf("INSERTED AS RESULT : %s\n", temp);
}
/*DELETE THE STRING IN SPECIFIC POSITION*/
void Delete(String *s, int position, int len)
{
    if (position < 0 || position > s->length || len > s->length - position) //Length > s->length-position
        return;
    char *temp = (char *)malloc((s->length - position) * sizeof(char));
    int i;
    //front
    for (i = 0; i < position; i++)
        temp[i] = s->string[i];
    //rear-end
    int j = position + len; //delete the middle of string in specific position
    for (; j < s->length; j++)
    {
        temp[i] = s->string[j];
        i++;
    }
    temp[i] = '\0';
    s->string = temp;
    s->length = s->length - len;
    printf("DELETED AS RESULT : %s\n", temp);
}
/*PRINT THE STRING*/
void print(String *s)
{
    if (s) // SO SIMPLE SO COOL ~
        printf("%s\n", s->string);
}
