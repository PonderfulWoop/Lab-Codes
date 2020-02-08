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

Token genToken(){
    return tkns[start++];
}
void T();
void E();

void E(){
    lookahead = genToken();
    if(strcmp(lookahead.type, "Numeric") == 0){
        lookahead = genToken();
        T();
    }
    else{
        printf("Failure\n");
        exit(1);
    }
}

void T(){
    if(strcmp(lookahead.lexname, "*") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.type, "Numeric") == 0){
            lookahead = genToken();
            T();
        }
        else{
            printf("Failure\n");
            return;
        }
    }
    else if(strcmp(lookahead.lexname, "$") == 0){
        printf("Success\n");
        return;
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
        printf("%s\t", tkns[i].lexname);
    printf("\n");
    E();
}