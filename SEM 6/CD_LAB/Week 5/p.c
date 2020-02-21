#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_lexan.c"

#define MAX 200

Token lookahead;
Token tkns[MAX];
int tkn_count = 0;
int start = 0;

Token genToken(){
    return tkns[start++];
}

void Program();
void declarations();
void statement_list();
void identifier_list();
void statement();
void expn();
void simple_expn();
void eprime();
void seprime();
void tprime();

void Program(){
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "int") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.lexname, "main") == 0){
            lookahead = genToken();
            if(strcmp(lookahead.lexname, "(") == 0){
                lookahead = genToken();
                if(strcmp(lookahead.lexname, ")") == 0){
                    lookahead = genToken();
                    if(strcmp(lookahead.lexname, "{") == 0){
                        declarations();
                        statement_list();
                        lookahead = genToken();
                        if(strcmp(lookahead.lexname, "}") == 0){
                            return;
                        }
                    }
                }
            }
        }
    }
}

void declarations(){
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "int") == 0 || strcmp(lookahead.lexname, "char") == 0){
        identifier_list();
        lookahead = genToken();
        if(strcmp(lookahead.lexname, ";") == 0){
            declarations();
        }
        else{
            printf("Error - Expected ;\n");
            exit(1);
        }
    }
    else if(strcmp(lookahead.type, "Identifier") == 0 || strcmp(lookahead.lexname, "}") == 0){
        start--;
        return;
    }
    else{
        printf("Error - Expected int or char\n");
        exit(1);
    }
}

void identifier_list(){
    lookahead = genToken();
    if(strcmp(lookahead.type, "Identifier") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.lexname, ",") == 0){
            identifier_list();
        }
        else if(strcmp(lookahead.lexname, "[") == 0){
            lookahead = genToken();
            if(strcmp(lookahead.type, "Numeric") == 0){
                lookahead = genToken();
                if(strcmp(lookahead.lexname, "]") == 0){
                    lookahead = genToken();
                    if(strcmp(lookahead.lexname, ",") == 0){
                        identifier_list();
                    }
                    else{
                        start--;
                        return;
                    }
                }
            }
        }
        else{
            start--;
        }
    }
}

void statement_list(){
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "}") == 0){
        start--;
        return;
    }
    else{
        statement();
        statement_list();
    }
}

void statement(){
    lookahead = genToken();
    if(strcmp(lookahead.type, "Identifier") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.lexname, "=") == 0){
            expn();
            lookahead = genToken();
            if(strcmp(lookahead.lexname, ";") == 0){
                return;
            }
            else{
            	printf("Error - Expected ;\n");
            	exit(1);
            }
        }
    }
}

void expn(){
    lookahead = genToken();
    if(strcmp(lookahead.type, "Identifier") == 0 || strcmp(lookahead.lexname, "Numeric") == 0){
        start--;
        simple_expn();
        eprime();
    }
}

void eprime(){
    lookahead = genToken();
    if(strcmp(lookahead.type, "Relational")){
        simple_expn();
    }
    else{
        start--;
        return;
    }
}

void simple_expn(){
    lookahead = genToken();
    if(strcmp(lookahead.type, "Identifier") == 0 || strcmp(lookahead.type, "Numeric") == 0){
        tprime();
        seprime();
    }
}

void seprime(){
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "+") == 0 || strcmp(lookahead.lexname, "-") == 0){
        simple_expn();
    }
    else{
        start --;
        return;
    }
}

void tprime(){
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "*") == 0 || strcmp(lookahead.lexname, "/") == 0 || strcmp(lookahead.lexname, "%") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.type, "Identifier") == 0 || strcmp(lookahead.type, "Numeric") == 0){
            tprime();
        }
    }
    else{
        start--;
        return;
    }
}



int main(){
    char c;
    FILE *fp = fopen("h.c", "rb+");
    c = fgetc(fp);

    while(c != EOF){
        char buff[30];
        int i = 0;

        while (c == ' ' || c == '\t')
            c = fgetc(fp);

        while (c == '/')
        {
            c = fgetc(fp);
            if (c == '/')
            {
                while (c != '\n')
                    c = fgetc(fp);
            }
            else if (c == '*')
            {
                while (c != '/')
                    c = fgetc(fp);
            }
        }

        while (delimiter(c) == 0 && c != EOF)
        {
            buff[i++] = c;
            c = fgetc(fp);
        }
        
        buff[i] = '\0';
        Token t = getNextToken(buff, 0, 0);
        if(t.row != -1)
            tkns[tkn_count++] = t;

        if(delimiter(c) && c != ' ' && c != '\n'){

            if (c == '<' || c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '>')
            {
                char k = fgetc(fp);
                if (k == '=' || (c == '+' && k == '+') || (c == '-' && k == '-'))
                {
                    char tempb1[3];
                    tempb1[0] = c;
                    tempb1[1] = k;
                    tempb1[2] = '\0';
                    Token temp = getNextToken(tempb1, 0, 0);
                    if (temp.row != -1)
                        tkns[tkn_count++] = temp;
                }
                else
                {
                    fseek(fp, -1, SEEK_CUR);
                    char tempb[2];
                    tempb[0] = c;
                    tempb[1] = '\0';
                    Token temp = getNextToken(tempb, 0, 0);
                    if (temp.row != -1)
                        tkns[tkn_count++] = temp;
                }
            }
            else
            {
                char tempb[2];
                tempb[0] = c;
                tempb[1] = '\0';
                Token temp = getNextToken(tempb, 0, 0);
                if (temp.row != -1)
                    tkns[tkn_count++] = temp;
            }
        }

        c = fgetc(fp);
    }
    fclose(fp);

    for(int i = 0; i<tkn_count; i++)
        printf("%s\t", tkns[i].lexname);
    printf("\n");

    Program();
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "$") == 0){
            printf("Success\n");
            exit(0);
    }
    else{
        printf("Failure\n");
        exit(1);
    }
}