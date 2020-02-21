#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TableLength 30
#define max_tokens 300

struct Token{

    char lexemename[30];
    unsigned int row, col;
    char type[30];
    char id_type[10];
    char Scope;
    int arg;
    int no_of_args;
    int size;
    char ret_type[10];
};

typedef struct Token Token;

struct ListElement{

    Token token;
    struct ListElement *next;
};

typedef struct ListElement ListElement;

ListElement *TABLE[TableLength];
Token tkns[max_tokens];
int tkn_count = 0;

void init(){
    for(int i = 0; i<TableLength; i++)
        TABLE[i] = NULL;
}

FILE *ignorePreprop(FILE *fp)
{
    int flag = 0;
    char ca = fgetc(fp);
    while (ca == '#')
    {
        while (ca != '\n')
            ca = fgetc(fp);
        ca = fgetc(fp);
    }
    return fp;
}

int isArith(char str[])
{
    if (!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/") || !strcmp(str, "=") || !strcmp(str, "++") || !strcmp(str, "--"))
        return 1;
    return 0;
}

int isRelational(char str[])
{
    if (!strcmp(str, "<") || !strcmp(str, ">") || !strcmp(str, "<=") || !strcmp(str, ">=") || !strcmp(str, "==") || !strcmp(str, "!="))
        return 1;
    return 0;
}

int isNumeric(char str[])
{
    for (int i = 0; i < strlen(str); i++)
        if (!isdigit(str[i]))
            return 0;

    return 1;
}

int isLogical(char str[])
{
    if (!strcmp(str, "&&") || !strcmp(str, "||"))
        return 1;
    return 0;
}

int isLiteral(char str[])
{
    if (str[0] == '"' && str[strlen(str) - 1] == '"')
        return 1;
    return 0;
}

int isSpecial(char buff[])
{
    if (!strcmp(buff, "("))
        return 1;
    else if (!strcmp(buff, ")"))
        return 2;
    else if (!strcmp(buff, ","))
        return 3;
    else if (!strcmp(buff, ";"))
        return 4;
    else if (!strcmp(buff, "{"))
        return 5;
    else if (!strcmp(buff, "}"))
        return 6;
    else if (!strcmp(buff, "["))
        return 7;
    else if (!strcmp(buff, "]"))
        return 8;
    return 0;
}

int isKeyword(char str[])
{
    if (!strcmp(str, "auto") || !strcmp(str, "default") || !strcmp(str, "signed") || !strcmp(str, "enum") || !strcmp(str, "extern") || !strcmp(str, "for") || !strcmp(str, "register") || !strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "int") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "const") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto") || !strcmp(str, "union") || !strcmp(str, "volatile"))
        return (1);
    return (0);
}

int isIdentifier(char str[])
{
    if (isdigit(str[0]) && isSpecial(str))
        return 0;
    else
    {
        for (int i = 1; i < strlen(str); i++)
            if (!isalnum(str[i]) && str[i] != '_')
                return 0;
    }

    return 1;
}

Token getNextToken(char lexname[], int row, int col)
{
    Token t;
    if (isArith(lexname))
    {
        strcpy(t.lexemename, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Arithmetic");
    }
    else if (isRelational(lexname))
    {
        strcpy(t.lexemename, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Relational");
    }
    else if (isKeyword(lexname))
    {
        strcpy(t.lexemename, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Keyword");
    }
    else if (isLogical(lexname))
    {
        strcpy(t.lexemename, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Logical");
    }
    else if (isSpecial(lexname) > 0)
    {
        strcpy(t.lexemename, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Special Symbol");
    }
    else if (isNumeric(lexname))
    {
        strcpy(t.lexemename, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Numeric");
    }
    else if (isIdentifier(lexname))
    {
        strcpy(t.lexemename, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Identifier");
    }
    else if (isLiteral(lexname))
    {
        strcpy(t.lexemename, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Literal");
    }
    else
    {
        t.row = -1;
    }
    return t;
}

int getSize(char *str){
	if(strcmp(str, "int") == 0)
		return 4;
	else if(strcmp(str, "float") == 0)
		return 4;
	else if(strcmp(str, "char") == 0)
		return 1;
	else if(strcmp(str, "double") == 0)
		return 8;
	else if(strcmp(str, "long") == 0)
		return 8;
}

int HASH(char *str){

    //Hashing based on first character
    char ch = str[0];
    if(str[0] == '_')
        return 26; //alphabets take till 25
    else if(str[0] >= 'A' && str[0] <= 'Z')
        return ch - 'A';
    
    return ch - 'a';
}

void Display(){

    //Write Display routine
    int i = 0;
    printf("no.\tname\ttype\tsize\targ\tscope\tno. of args\treturn type\n");
    for(int i = 0; i<TableLength; i++){
    	while(TABLE[i] != NULL){
    		printf("%d\t%s\t%s\t%d\t<%d>\t%c\t%d\t\t%s\n", HASH(TABLE[i]->token.lexemename), TABLE[i]->token.lexemename, TABLE[i]->token.id_type, TABLE[i]->token.size, TABLE[i]->token.arg, TABLE[i]->token.Scope, TABLE[i]->token.no_of_args, TABLE[i]->token.ret_type);
    		TABLE[i] = TABLE[i]->next;
    	}
    }
}

int SEARCH(char *str){
    int start = HASH(str);
    ListElement *ptr = TABLE[start];
    if(ptr == NULL)
        return 0;
    else{
        while(ptr != NULL){
            if(strcmp(ptr->token.lexemename, str) == 0)
                return 1;
            ptr = ptr->next;
        }
        return 0;
    }
}

void INSERT(Token tkn){
    if(SEARCH(tkn.lexemename))
        return;
    int val = HASH(tkn.lexemename);
    ListElement *cur = (ListElement*)malloc(sizeof(ListElement));
    cur->token = tkn;
    cur->next = NULL;

    if(TABLE[val] == NULL)
        TABLE[val] = cur;
    else{
        ListElement *temp = TABLE[val];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = cur;
    }
}

int main()
{
    //initialize Symbol table
    init();


    char c;
    FILE *fp = fopen("test.c", "r");
    if (fp == NULL)
    {
        exit(0);
    }
    fp = ignorePreprop(fp);
    c = fgetc(fp);

    int line = 0;
    int col = 1;
    while (c != EOF)
    {
        char buff[30];
        int i = 0;
        if (c == '/')
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
                {
                    c = fgetc(fp);
                }
            }
        }

        while (c != ' ' && c != '\n' && c != EOF)
        {
            buff[i++] = c;
            c = fgetc(fp);
        }
        if (c == ' ')
            col++;
        else if (c == '\n')
        {
            line++;
            col = 1;
        }
        buff[i] = '\0';
        Token tkn = getNextToken(buff, line, col);
        if(tkn.row!=-1 && tkn_count>3){
            if(strcmp(tkn.type, "Identifier") == 0){
                printf("<%s, %d, %d, %d>\n",tkn.lexemename,tkn.row,tkn.col,HASH(tkn.lexemename));
            }
            else{
                printf("<%s, %d, %d, %s>\n",tkn.lexemename,tkn.row,tkn.col,tkn.type);
            }

         }
        if (tkn.row != -1)
        {
        	tkns[tkn_count++] = tkn;
        }
        c = fgetc(fp);
    }

    for(int i = 0; i<tkn_count; i++){
    	if(strcmp(tkns[i].type, "Identifier") == 0 && SEARCH(tkns[i].lexemename) == 0 && strcmp(tkns[i].lexemename, "printf") != 0 && strcmp(tkns[i].lexemename, "scanf") != 0 && strcmp(tkns[i].lexemename, "sqrt") != 0){

    		if(strcmp(tkns[i+1].lexemename, "(") == 0){
    			strcpy(tkns[i].id_type, "FUNC");
    			strcpy(tkns[i].ret_type, tkns[i-1].lexemename);

    			tkns[i].size = 0;

    			if(strcmp(tkns[i+2].lexemename, ")") == 0)
    				tkns[i].no_of_args = 0;
    			else
    				tkns[i].no_of_args = 1;
    			if(tkns[i].no_of_args == 1){
    				tkns[i].arg = HASH(tkns[i+3].lexemename);
    			}
    			else{
    				tkns[i].arg = 9999;
    			}
    			tkns[i].Scope = '-';
    		}
    		else{
    			strcpy(tkns[i].id_type, tkns[i-1].lexemename);
    			strcpy(tkns[i].ret_type, " ");
    			tkns[i].no_of_args = 0;
    			tkns[i].size = getSize(tkns[i].id_type);
    			tkns[i].arg = 9999;
    			if(strcmp(tkns[i+1].lexemename, "[") == 0){
    				int num = atoi(tkns[i+2].lexemename);
    				tkns[i].size = getSize(tkns[i].id_type) * num;
    			}
    			for(int j = i-1; j>=0; j--){
    				if(strcmp(tkns[j].lexemename, "{") == 0 || strcmp(tkns[j].lexemename, "(") == 0){
    					tkns[i].Scope = 'L';
    					break;
    				}
    			}
    			if(tkns[i].Scope != 'L')
    				tkns[i].Scope = 'G';
    		}

    		INSERT(tkns[i]);
        }
    }

    Display();
    fclose(fp);
}