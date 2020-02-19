#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_lexan.c"

#define MAX 200

char str[30];
Token lookahead;
Token tkns[MAX];
int tkn_count = 0;
int start = 0;

char first_lexp[20][10] = {"number", "id", "(", "\0"};
char follow_lexp[20][10] = {"$", "number", "id", "(", ")", "\0"};

char first_aterm[20][10] = {"number", "id", "\0"};
char follow_aterm[20][10] = {"$", "number", "id", "(", ")", "\0"};

char first_list[20][10] = {"(", "\0"};
char follow_list[20][10] = {"$", "number", "id", "(", ")", "\0"};

char first_lexpSeq[20][10] = {"number", "id", "(", "\0"};
char follow_lexpSeq[20][10] = {")", "\0"};

char first_lexpSeqd[20][10] = {"number", "id", "(", "\0"};
char follow_lexpSeqd[20][10] = {")", "\0"};

Token genToken()
{
    return tkns[start++];
}

int inFirst(char *str, char t){
    int i = 0;
    if(t == '1'){
        while(strcmp(first_lexp[i], "\0") != 0){
            if(strcmp(str, first_lexp[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == '2'){
        while(strcmp(first_aterm[i], "\0") != 0){
            if(strcmp(str, first_aterm[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == '3'){
        while(strcmp(first_list[i], "\0") != 0){
            if(strcmp(str, first_list[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == '4'){
        while(strcmp(first_lexpSeq[i], "\0") != 0){
            if(strcmp(str, first_lexpSeq[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else{
        while(strcmp(first_lexpSeqd[i], "\0") != 0){
            if(strcmp(str, first_lexpSeqd[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
}

int inFollow(char *str, char t){
    int i = 0;
    if(t == '1'){
        while(strcmp(follow_lexp[i], "\0") != 0){
            if(strcmp(str, follow_lexp[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == '2'){
        while(strcmp(follow_aterm[i], "\0") != 0){
            if(strcmp(str, follow_aterm[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == '3'){
        while(strcmp(follow_list[i], "\0") != 0){
            if(strcmp(str, follow_list[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == '4'){
        while(strcmp(follow_lexpSeq[i], "\0") != 0){
            if(strcmp(str, follow_lexpSeq[i]) == 0)
                return 1;
            i++;
        }
        return 0;  
    }
    else{
        while(strcmp(follow_lexpSeqd[i], "\0") != 0){
            if(strcmp(str, follow_lexpSeqd[i]) == 0)
                return 1;
            i++;
        }
        return 0;  
    }
}

void lexp();
void aterm();
void list();
void lexp_Seq();
void lexp_Seqd();

void lexp(){

    lookahead = genToken();
    if (inFirst(lookahead.lexname, '1')){
        start--;
        if (strcmp(lookahead.lexname, "(") == 0){
            list();
        }
        else
            aterm();
    }
    else{
        printf("Error in lexp -- Expected number, id, (\n");
        exit(1);
    }
}

void aterm(){
    lookahead = genToken();
    if (inFirst(lookahead.lexname, '2')){
        //do nothing
    }
}

void list(){
    lookahead = genToken();
    if (inFirst(lookahead.lexname, '3')){
        lexp_Seq();
    }
    else{
        printf("Error in list -- Expected (\n");
        exit(1);
    }
}

void lexp_Seq(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, '4')){
        start--;
        lexp();
        lexp_Seqd();
    }
    else{
        printf("Error in lexp_Seq -- Expected number, (, id\n");
        exit(1);
    }
}

void lexp_Seqd(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, '5')){
        start--;
        lexp();
        lexp_Seqd();
    }
    else if(inFollow(lookahead.lexname, '5')){
        //do nothing
    }
    else{
        printf("Error in lexp_Seq -- Expected number, (, id\n");
        exit(1);
    }
}

int main()
{
    char c;
    FILE *fp = fopen("h.c", "r");
    //Ignores preprop
    c = fgetc(fp);

    while (c != EOF){
        char buff[30];
        int i = 0;

        while (c == ' ' || c == '\t')
            c = fgetc(fp);

        while (delimiter(c) == 0 && c != EOF)
        {
            buff[i++] = c;
            c = fgetc(fp);
        }

        buff[i] = '\0';
        Token t = getNextToken(buff, 0, 0);

        if (t.row != -1)
            tkns[tkn_count++] = t;

        if (delimiter(c) && c != ' ' && c != '\n')
        {
            char tempb[2];
            tempb[0] = c;
            tempb[1] = '\0';
            Token temp = getNextToken(tempb, 0, 0);
            tkns[tkn_count++] = temp;
        }

        c = fgetc(fp);
    }

    for (int i = 0; i < tkn_count; i++)
        printf("%s\t", (tkns[i]).lexname);
    printf("\n");

    lexp();
    lookahead = genToken();
    if (strcmp(lookahead.lexname, "$") == 0)
    {
        printf("Success\n");
        exit(0);
    }
}