#ifndef _STRING_H_
#define _STRING_H_

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
int strCompete(String *s, String *t);
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

#endif