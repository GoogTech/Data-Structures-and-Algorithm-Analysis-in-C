#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
/*THEME:STRING-FUNCTION TIME:18/11/23/12:30*/

//-------------------------DECLARE----------------------------------
/*DEFIND THE STRUCT*/
typedef struct string
{
    char *string;
    int length;
} String;

/*DECLARE THE FUNCTIONS*/
/*COPY THE STRING OF P TO S*/
void strAssign(String *s, char *p);
/*GET THE LENGTH OF STRING*/
int strLength(String *s);
/*WHETHER IT'S EQUAL*/
int strEqual(String *s, String *t);
/*COMPETE TO THE SIZE OF BETWEN S AND T*/
int strCompare(String *s, String *t);
/*CONNECT THE STRING OF S AND T*/
void strConnect(String *s, String *t);
/*COPY TO S FROM T*/
void strCopy(String *s, String *t);
/*INSERT THE STRING OF P IN SPECIFIC POSITION*/
void Insert(String *s, int position, char *p);
/*DELETE SPECIFIC STRING*/
void Delete(String *s, int position, int length);
/*PRINT THE STRING*/
void print(String *s);

//--------------------------FUNCTIONS---------------------------------
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
    memset(s->string, '\0', t->length + 1); // ╰(*°▽°*)╯ +1 ?
    for (int i = 0; i <= t->length; i++)
        s->string[i] = t->string[i];
    s->length = t->length;
}
/*DEMINTER WHETHER OR NOT THEY ARE EQUAL*/
int strEqual(String *s, String *t)
{
    if (s->length == t->length)
    {
        while (*(s->string++) != *(t->string))
        {
            printf("TWO STRINGS ARE NOT EQUAL !n");
            return 0;
        }
        printf("TWO STRINGS ARE EQUAL !\n");
        return 1;
    }
    printf("TWO STRINGS ARE NOT EQUAL !\n");
    return 0;
}
/*CONNECT THE STRING OF S AND T*/
void strConnect(String *s, String *t)
{
    int len = s->length + t->length;
    char *temp = (char *)malloc((s->length + t->length) * sizeof(char));
    //╰(*°▽°*)╯
    //memset(temp, '\0', s->length);
    memset(temp, '\0', len);
    int i, j;
    for (i = 0; i < s->length; i++)
        temp[i] = s->string[i];
    for (j = 0; j < t->length; j++, i++)
        temp[i] = t->string[j];
    temp[i] = '\0';
    s->string = temp;
    s->length = s->length + t->length;
}
//Compares the sizes of two strings
int strCompare(String *s, String *t)
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
    memset(temp, '\0', (s->length + p_length)); //╰(*°▽°*)╯ ~
    int i;
    //front
    for (int i = 0; i < position; i++)
        temp[i] = s->string[i];
    int j = 0;
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
    printf("INSERTED AS RESULT : %s\n", temp); //NOTICE × × × × ×
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
    //╰(*°▽°*)╯ ? the type of temp ? BUT THE OPERATION RESULTS ARE CORRECT !
    printf("DELETED AS RESULT : \n%s\n", temp);
}
/*PRINT THE STRING*/
void print(String *s)
{
    if (s) // SO SIMPLE SO COOL ~
        printf("%s\n", s->string);
}

//--------------------------MAIN---------------------------------
int main(int argc, char const *argv[])
{
    // S
    String s;
    char arr[1024];
    printf("(S)PLEASE INPUT THE DATA OF STRING :\n");
    scanf("%s", arr);
    strAssign(&s, arr);
    printf("--- THE STRING OF S --- \n");
    print(&s);
    printf("--- THE LENGTH OF S --- \n%d\n", strLength(&s));
    printf("\n");

    // T
    String t;
    printf("(T)PLEASE INPUT THE DATA OF STRING : \n");
    scanf("%s", arr);
    strAssign(&t, arr);
    printf("--- THE STRING OF T ---\n");
    print(&t);
    printf("--- THE LENGTH OF T ---\n%d\n", strLength(&t));
    printf("\n");

    //Determine whether or not they are equal
    printf("--- DETERMINE WHETHER OR NOT THEY ARE EQUAL ---\n");
    strEqual(&s, &t);
    printf("\n");

    //Compares the sizes of two strings
    printf("--- Compares the sizes of two strings ---\n");
    int result = strCompare(&s, &t);
    if (result < 0)
        printf("T STRING IS LARGE !\n");
    if (result == 0)
        printf("The S string is the same as the T string !\n");
    if (result > 0)
        printf("S STRING IS LARGE !\n");
    printf("\n");

    //Concatenate two strings
    printf("--- Concatenate two strings ---\n");
    strConnect(&s, &t);
    printf("-- THE RESULT -- \n");
    print(&s);
    printf("-- THE LENGTH OF RESULT --\n%d\n", strLength(&s));
    printf("\n");

    //Copy the string T into the string S
    printf("--- Copy the string T into the string S ---\n");
    strCopy(&s, &t);
    printf("-- THE RESULT --\n");
    print(&s);
    printf("-- THE LENGTH OF RESULT -- \n%d\n", strLength(&s));
    printf("\n");

    //-------------------------BUG----------------------------------
    //Inserts the specified string into the string S
    //int p;
    // printf("--- Inserts the specified string into the string S ---\n");
    // printf("PLEASE ENTER THE SPECIFIED STRING : \n");
    // scanf("%s", arr);
    // //printf("PLEASE ENTER THE SPECIFIED POSITION : \n");
    // //scanf("%d", &p);
    // Insert(&s, 3, arr);
    // // printf("-- INSERTED AS RESULT --\n");
    // // print(&s);
    // printf("\n");

    //Deletes a substring of the S string
    int d_position, d_length;
    printf("--- Deletes a substring of the S string ---\n");
    printf("SPECIFIED POSITION : \n");
    scanf("%d", &d_position);
    printf("SPECIFIED LENGTH : \n");
    scanf("%d", &d_length);
    Delete(&s, d_position, d_length);
    printf("THE LENGTH OF DELETED STRING : \n%d\n", strLength(&s));

    system("pause");
    //Thanks♪(･ω･)ﾉ for 'system("pause")'
    //getchar();
    return 0;
}
