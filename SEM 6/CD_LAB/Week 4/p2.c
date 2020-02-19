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

char first_S[20][5] = {"a", "\0"};
char follow_S[20][5] = {"$", "\0"};

char first_A[20][5] = {"b", "\0"};
char follow_A[20][5] = {"c", "\0"};

char first_Ad[20][5] = {"b", "@", "\0"};
char follow_Ad[20][5] = {"c", "\0"};

char first_B[20][5] = {"d", "\0"};
char follow_B[20][5] = {"e", "\0"};

Token genToken(){
    return tkns[start++];
}

int inFirst(char *str, char t){
    int i = 0;
    if(t == 'S'){
        while(strcmp(first_S[i], "\0") != 0){
            if(strcmp(str, first_S[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == 'A'){
        while(strcmp(first_A[i], "\0") != 0){
            if(strcmp(str, first_A[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == 'B'){
        while(strcmp(first_B[i], "\0") != 0){
            if(strcmp(str, first_B[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else{
        while(strcmp(first_B[i], "\0") != 0){
            if(strcmp(str, first_Ad[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
}

int inFollow(char *str, char t){
    int i = 0;
    if(t == 'S'){
        while(strcmp(follow_S[i], "\0") != 0){
            if(strcmp(str, follow_S[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == 'A'){
        while(strcmp(follow_A[i], "\0") != 0){
            if(strcmp(str, follow_A[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else if(t == 'B'){
        while(strcmp(follow_B[i], "\0") != 0){
            if(strcmp(str, follow_B[i]) == 0)
                return 1;
            i++;
        }
        return 0;
    }
    else{
        while(strcmp(follow_Ad[i], "\0") != 0){
            if(strcmp(str, follow_Ad[i]) == 0)
                return 1;
            i++;
        }
        return 0;  
    }
}

void S();
void A();
void Ad();
void B();

void S(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, 'S')){
        A();
    }
    else{
        printf("Error in S -- Expected a\n");
        exit(1);
    }
}

void A(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, 'A')){
        Ad();
    }
    else{
        printf("Error in A -- Expected b\n");
        exit(1);
    }
}

void Ad(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, '-')){
        Ad();
    }
    else if(inFollow(lookahead.lexname, '-')){
        B();
    }
    else{
        printf("Error in Ad -- Expected b or c\n");
        exit(1);
    }
}

void B(){
    lookahead = genToken();
    if(inFirst(lookahead.lexname, 'B')){
        lookahead = genToken();
        if(strcmp(lookahead.lexname, "e") == 0){
            //do nothing
        }
        else{
            printf("Error in B -- Expected e\n");
            exit(1);
        }
    }
    else{
        printf("Error in B -- Expected d\n");
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
        printf("%s\t", tkns[i].lexname);
    printf("\n");

    S();
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "$") == 0){
            printf("Success\n");
            exit(0);
    }
    else{
        printf("Error -- Expected $\n");
        exit(1);
    }
}