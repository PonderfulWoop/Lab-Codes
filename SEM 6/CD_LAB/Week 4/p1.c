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

char first_S[20][5] = {"a", ">", "(", "\0"};
char follow_S[20][5] = {"$", ",", ")", "\0"};

char first_T[20][5] = {"a", ">", "(", "\0"};
char follow_T[20][5] = {")", "\0"};

char first_Td[20][5] = {",", "@", "\0"};
char follow_Td[20][5] = {")", "\0"};

Token genToken(){
    return tkns[start++];
}

int inFirst(char *str, char t){
    int i = 0;
    if(t == 'S'){
        while(i<4){
            if(strcmp(str, first_S[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == 'T'){
        while(i<4){
            if(strcmp(str, first_T[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else{
        while(i<3){
            if(strcmp(str, first_Td[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
}

int inFollow(char *str, char t){
    int i = 0;
    if(t == 'S'){
        while(i<4){
            if(strcmp(str, follow_S[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == 'T'){
        while(i<4){
            if(strcmp(str, follow_T[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else{
        while(i<3){
            if(strcmp(str, follow_Td[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
}

void S();
void T();
void Td();

void S(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, 'S')){
        if(strcmp(lookahead.lexname, "(") == 0){
            T();
        }
    }
    else{
        printf("Error in S -- Expected a, >, (\n");
        exit(1);
    }
}

void T(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, 'T')){
        start--;
        S();
        Td();
    }
    else{
        printf("Error in T -- Expected a, >, (\n");
        exit(1);
    }
}

void Td(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, '-')){
        S();
        Td();
    }
    else if(inFollow(lookahead.lexname, '-')){
        //do nothing
    }
    else{
        printf("Error in Td -- Expected , or )\n");
        exit(1);
    }
}

int main(){
    char c;
    FILE *fp = fopen("h.c", "r");
    //Ignores preprop
    c = fgetc(fp);

    while(c != EOF){
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
        
        if(t.row != -1)
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
    for(int i = 0; i<tkn_count; i++)
        printf("%s\t", (tkns[i]).lexname);
    printf("\n");

    S();
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "$") == 0){
            printf("Success\n");
            exit(0);
        }
}