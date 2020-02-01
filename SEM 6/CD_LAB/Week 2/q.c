#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Token{
	char lexemename[30];
	unsigned int row, col;
	char type[30];
};


typedef struct Token Token;

FILE* ignorePreprop(FILE *fp){
	int flag = 0;
	char ca = fgetc(fp);
	while(ca == '#'){
		while(ca != '\n')
			ca = fgetc(fp);
		ca = fgetc(fp);
	}

	return fp;
}

int isArith(char str[]){
	if(!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/") || !strcmp(str, "="))
		return 1;
	return 0;
}

int isRelational(char str[]){
	if(!strcmp(str, "<") || !strcmp(str, ">") || !strcmp(str, "<=") || !strcmp(str, ">=") || !strcmp(str, "==") || !strcmp(str, "!="))
		return 1;
	return 0;
}

int isNumeric(char str[]){
	for(int i = 0; i<strlen(str); i++)
		if(!isdigit(str[i]))
			return 0;

	return 1;
}

int isLogical(char str[]){
	if(!strcmp(str, "&&") || !strcmp(str, "||"))
		return 1;
	return 0;
}

int isLiteral(char str[]){
	if(str[0] == '"' && str[strlen(str)-1] == '"')
		return 1;
	return 0;
}

int isSpecial(char buff[]){
	if(!strcmp(buff,"("))
		return 1;
	else if(!strcmp(buff,")"))
		return 2;
	else if(!strcmp(buff,","))
		return 3;
	else if(!strcmp(buff,";"))
		return 4;
	else if(!strcmp(buff,"{"))
		return 5;
	else if(!strcmp(buff,"}"))
		return 6;
	return 0;
}

int isKeyword(char str[]){
	if (!strcmp(str, "auto") || !strcmp(str, "default")  
        || !strcmp(str, "signed") || !strcmp(str, "enum")  
        || !strcmp(str, "extern") || !strcmp(str, "for")  
        || !strcmp(str, "register") || !strcmp(str, "if")  
        || !strcmp(str, "else")  || !strcmp(str, "int") 
        || !strcmp(str, "while") || !strcmp(str, "do") 
        || !strcmp(str, "break") || !strcmp(str, "continue")  
        || !strcmp(str, "double") || !strcmp(str, "float") 
        || !strcmp(str, "return") || !strcmp(str, "char") 
        || !strcmp(str, "case") || !strcmp(str, "const") 
        || !strcmp(str, "sizeof") || !strcmp(str, "long") 
        || !strcmp(str, "short") || !strcmp(str, "typedef") 
        || !strcmp(str, "switch") || !strcmp(str, "unsigned") 
        || !strcmp(str, "void") || !strcmp(str, "static") 
        || !strcmp(str, "struct") || !strcmp(str, "goto") 
        || !strcmp(str, "union") || !strcmp(str, "volatile")) 
        return (1); 
    return (0); 
}

int isIdentifier(char str[]){
	if(isdigit(str[0]) && isSpecial(str))
		return 0;
	else{
		for(int i = 1; i<strlen(str); i++)
			if(!isalnum(str[i]) && str[i] != '_')
				return 0;
	}

	return 1;
}

Token getNextToken(char lexname[], int row, int col){
	Token t;
	if(isArith(lexname)){
		strcpy(t.lexemename, lexname);
		t.row = row;
		t.col = col;
		strcpy(t.type, "Arithmetic");
	}
	else if(isRelational(lexname)){
		strcpy(t.lexemename, lexname);
		t.row = row;
		t.col = col;
		strcpy(t.type, "Relational");
	}
	else if(isKeyword(lexname)){
		strcpy(t.lexemename, lexname);
		t.row = row;
		t.col = col;
		strcpy(t.type, "Keyword");
	}
	else if(isLogical(lexname)){
		strcpy(t.lexemename, lexname);
		t.row = row;
		t.col = col;
		strcpy(t.type, "Logical");
	}
	else if(isSpecial(lexname) > 0){
		strcpy(t.lexemename, lexname);
		t.row = row;
		t.col = col;
		strcpy(t.type, "Special Symbol");
	}
	else if(isNumeric(lexname)){
		strcpy(t.lexemename, lexname);
		t.row = row;
		t.col = col;
		strcpy(t.type, "Numeric");
	}
	else if(isIdentifier(lexname)){
		strcpy(t.lexemename, lexname);
		t.row = row;
		t.col = col;
		strcpy(t.type, "Identifier");
	}
	else if(isLiteral(lexname)){
		strcpy(t.lexemename, lexname);
		t.row = row;
		t.col = col;
		strcpy(t.type, "Literal");
	}
	else{
		t.row = -1;
	}
	return t;
}

int main(){
	char c;
	FILE *fp = fopen("temp.c", "r");
	if(fp==NULL){
		exit(0);
	}
	fp = ignorePreprop(fp);
	c = fgetc(fp);

	int line = 0; 
	int col = 1;
	while(c != EOF){
		char buff[30];
		int i = 0;
		if(c == '/'){
			c = fgetc(fp);
			if(c == '/'){
				while(c != '\n')
					c = fgetc(fp);
			}
			else if(c == '*'){
				while(c != '/'){
					c = fgetc(fp);
				}
			}
		}

		while(c != ' ' && c != '\n' && c != EOF){
			buff[i++] = c;
			c = fgetc(fp);
		}
		if(c == ' ')
			col++;
		else if(c == '\n'){
			line++;
			col = 1;
		}
		buff[i] = '\0';
		Token tkn = getNextToken(buff,line,col);
		if(tkn.row!=-1){
		 	printf("<%s, %d, %d, %s>\n",tkn.lexemename,tkn.row,tkn.col,tkn.type);

		 }
		c = fgetc(fp);
	}
	fclose(fp);
}