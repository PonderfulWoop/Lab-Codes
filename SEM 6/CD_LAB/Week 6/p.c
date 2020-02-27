#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_lexan.c"

#define MAX 300

Token lookahead;
Token tkns[MAX];
int tkn_count = 0;
int start = 0;
FILE *fp;

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
void dprime();

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
                        else{
                            printf("Error - Expected }\n");
                            exit(1);
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
                else{
                    printf("Error - Expected ]\n");
                    exit(1);
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
    if (strcmp(lookahead.lexname, "}") == 0 || strcmp(lookahead.lexname, "$") == 0){
        start--;
        return;
    }
    else{
        start--;
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
    else if(strcmp(lookahead.lexname, "if") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.lexname, "(") == 0){
            expn();
            lookahead = genToken();
            if(strcmp(lookahead.lexname, ")") == 0){
                lookahead = genToken();
                if(strcmp(lookahead.lexname, "{") == 0){
                    statement_list();
                    lookahead = genToken();
                    if(strcmp(lookahead.lexname, "}") == 0){
                        dprime();
                    }
                    else{
                        printf("Error - Expected }\n");
                        exit(1);
                    }
                }
                else{
                    printf("Error - Expected }\n");
                    exit(1);
                }
            }
            else{
                printf("Error - Expected )\n");
                exit(1);
            }
        }
        else{
            printf("Error - Expected (\n");
            exit(1);
        }
    }
    else if(strcmp(lookahead.lexname, "while") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.lexname, "(") == 0){
            expn();
            lookahead = genToken();
            if(strcmp(lookahead.lexname, ")") == 0){
                lookahead = genToken();
                if(strcmp(lookahead.lexname, "{") == 0){
                    statement_list();
                    lookahead = genToken();
                    if(strcmp(lookahead.lexname, "}") == 0){
                        //do nothing;
                    }
                }
            }
        }
    }
    else if(strcmp(lookahead.lexname, "for") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.lexname, "(") == 0){
            lookahead = genToken();
            if(strcmp(lookahead.type, "Identifier") == 0){
                start--;
                statement();
                expn();
                lookahead = genToken();
                if(strcmp(lookahead.lexname, ";") == 0){
                    lookahead = genToken();
                    if(strcmp(lookahead.type, "Identifier") == 0){
                        lookahead = genToken();
                        if (strcmp(lookahead.lexname, "=") == 0){
                            expn();
                            lookahead = genToken();
                            if(strcmp(lookahead.lexname, ")") == 0){
                                lookahead = genToken();
                                if(strcmp(lookahead.lexname, "{") == 0){
                                    statement_list();
                                    lookahead = genToken();
                                    if(strcmp(lookahead.lexname, "}") == 0){
                                        //do nothing;
                                    }
                                    else{
                                        printf("Error\n");
                                        exit(1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }
}

void expn(){
    simple_expn();
    eprime();
}

void dprime(){
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "else") == 0){
        lookahead = genToken();
        if(strcmp(lookahead.lexname, "{") == 0){
            statement_list();
            lookahead = genToken();
            if(strcmp(lookahead.lexname, "}") == 0){
                //do nothing;
            }
        }
    }
    else{
        start--;
        return;
    }
}

void eprime(){
    lookahead = genToken();
    if(strcmp(lookahead.type, "Relational") == 0){
        simple_expn();
    }
    else{
        start--;
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
        start--;
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
    }
}



int main(){
    init();
    char c;
    fp = fopen("h.c", "rb+"); //use rb+ for windows
    //Ignores preprop
    fp = ignorePreprop(fp);
    Token t;

    do
    {
        t = getNextToken(fp);
        if (t.row > -1){
            tkns[tkn_count++] = t;
        }
    }while(t.row != -999);
    fclose(fp);

    printf("Tokens: \n");
    for(int i = 0; i<tkn_count; i++)
        printf("%s\t", tkns[i].lexname);
    printf("\n===============================================================\n");

    //PARSING THE FILE
    Program();
    lookahead = genToken();
    if(strcmp(lookahead.lexname, "$") == 0){
            printf("Success in Parsing\n");
            exit(0);
    }
    else{
        printf("Failure, lookahead = %s\n", lookahead.lexname);
        lookahead = genToken();
        printf("\n%s", lookahead.lexname);
        exit(1);
    }
}