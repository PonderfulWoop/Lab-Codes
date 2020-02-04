#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Token
{
	char lexname[20];
	int row, col;
	char type[20];
};

typedef struct Token Token;

FILE* ignorePreprop(FILE* fp){
	char c = fgetc(fp);
	while(c == '#'){
		while(c != '\n')
			c = fgetc(fp);
		c = fgetc(fp);
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

int delimiter(char c){
	if( c == ' ' || isSpecial(&c))
		return 1;
	return 0;
}

Token getNextToken(char lexname[], int row, int col)
{
    Token t;
    if(lexname[0] == '\0'){
    	t.row = -1;
    }
    else if (isArith(lexname))
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Arithmetic");
    }
    else if (isRelational(lexname))
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Relational");
    }
    else if (isKeyword(lexname))
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Keyword");
    }
    else if (isLogical(lexname))
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Logical");
    }
    else if (isSpecial(lexname) > 0)
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Special Symbol");
    }
    else if (isNumeric(lexname))
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Numeric");
    }
    else if (isIdentifier(lexname))
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Identifier");
    }
    else if (isLiteral(lexname))
    {
        strcpy(t.lexname, lexname);
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

int main(){

	FILE* fp;
	fp = fopen("temp.c","r");
	fp = ignorePreprop(fp);

	char ca = fgetc(fp);
	int line = 0, col = 1;

	while(ca != EOF){
		char buff[30];
		int i = 0;

		while(ca == '/'){
			ca = fgetc(fp);
			if(ca == '/'){
				while(ca != '\n')
					ca = fgetc(fp);
			}
			else if(ca == '*'){
				while(ca != '/')
					ca = fgetc(fp);
			}
		}

		while(ca == ' ' || ca == '\t')
			ca = fgetc(fp);

		while(!delimiter(ca) && ca != '\n' && ca != EOF){
			col++;
			buff[i++] = ca;
			ca = fgetc(fp);
		}

		if(ca == '\n'){
			line++; col = 1;
		}
		buff[i] = '\0';

		Token t = getNextToken(buff, line, col);

		if(t.row != -1)
			printf("<%s, %d, %d, %s>\n",t.lexname,t.row,t.col,t.type);
		if(delimiter(ca) && ca != ' '){
			char tempb[2];
			tempb[0] = ca;
			tempb[1] = '\0';
			Token temp = getNextToken(tempb, line, ++col);
			if(temp.row != -1)
				printf("<%s, %d, %d, %s>\n",temp.lexname,temp.row,temp.col,temp.type);
		}
		//print Token

		ca = fgetc(fp);
	}

	fclose(fp);
}