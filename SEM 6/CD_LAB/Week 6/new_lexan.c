#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TableLength 30
#define max_tokens 300

struct Token
{
    char lexname[20];
    int row, col;
    char type[20];
};

typedef struct Token Token;

struct ListElement
{

    Token token;
    struct ListElement *next;
};

typedef struct ListElement ListElement;

ListElement *TABLE[TableLength];
int row = 0;
int col = 1;

void init()
{
    for (int i = 0; i < TableLength; i++)
        TABLE[i] = NULL;
}

FILE *ignorePreprop(FILE *fp)
{
    int flag = 0;
    char ca = fgetc(fp);
    while (ca == '#')
    {
        flag = 1;
        while (ca != '\n')
            ca = fgetc(fp);
        ca = fgetc(fp);
    }
    if (flag == 1)
        return fp;
    else
    {
        fseek(fp, 0, SEEK_SET);
        return fp;
    }
}

int isArith(char str[])
{
    if (!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/") || !strcmp(str, "=") || !strcmp(str, "++") || !strcmp(str, "--") || !strcmp(str, "%") || !strcmp(str, "-=") || !strcmp(str, "+=") || !strcmp(str, "*=") || !strcmp(str, "/="))
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
        return 1;
    else if (!strcmp(buff, ","))
        return 1;
    else if (!strcmp(buff, ";"))
        return 1;
    else if (!strcmp(buff, "{"))
        return 1;
    else if (!strcmp(buff, "}"))
        return 1;
    else if (!strcmp(buff, "["))
        return 1;
    else if (!strcmp(buff, "]"))
        return 1;
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

int delimiter(char c)
{
    char *delim = " +-*/,.;:><=!()[]{}%$\n";
    int len = strlen(delim);
    for (int i = 0; i < len; i++)
        if (c == delim[i])
            return 1;
    return 0;
}

Token getNextToken(FILE* fp)
{
    char c;
    char buff[30];
    Token t;
    int db_quote = 0;
    c = fgetc(fp);

    while (c != EOF)
    {
        memset(buff, '\0', sizeof(buff));
        int i = 0;

        while (c == ' ' || c == '\t')
            c = fgetc(fp);

        while (c == '/')
        {
            char p = fgetc(fp);
            if (p == '/')
            {
                while (p != '\n')
                    p = fgetc(fp);
            }
            else if (p == '*')
            {
                while (p != '/')
                    p = fgetc(fp);
                p = fgetc(fp);
            }
            else
            {
                fseek(fp, -1, SEEK_CUR);
                break;
            }
            c = p;
        }

        if (delimiter(c) && c != ' ' && c != '\n' && c != EOF)
        {
            if (c == '<' || c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '>')
            {
                char k = fgetc(fp);
                if (k == '=' || (c == '+' && k == '+') || (c == '-' && k == '-'))
                {
                    buff[0] = c;
                    buff[1] = k;
                    buff[2] = '\0';
                    col += 2;
                }
                else
                {
                    fseek(fp, -1, SEEK_CUR);
                    buff[0] = c;
                    buff[1] = '\0';
                    col++;
                }
            }
            else
            {
                buff[0] = c;
                buff[1] = '\0';
                col++;
            }
            break;
        }

        while ((delimiter(c) == 0 || (delimiter(c) == 1 && db_quote)) && c != EOF)
        {
            col++;
            buff[i++] = c;
            if (c == '"')
                db_quote = (db_quote + 1) % 2;
            c = fgetc(fp);
        }

        if (c == '\n')
        {
            row++;
            col = 1;
        }
        buff[i] = '\0';
        if (delimiter(c) && c != ' ' && c != '\n' && c != EOF)
            fseek(fp, -1, SEEK_CUR);
        break;
    }

    if (c == EOF)
    {
        t.row = -999;
        return t;
    }

    //---------Generate Token----------//
    if (buff[0] == '\0')
    {
        t.row = -1;
    }
    else if (isArith(buff))
    {
        strcpy(t.lexname, buff);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Arithmetic");
    }
    else if (isSpecial(buff))
    {
        strcpy(t.lexname, buff);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Special Symbol");
    }
    else if (isRelational(buff))
    {
        strcpy(t.lexname, buff);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Relational");
    }
    else if (isKeyword(buff))
    {
        strcpy(t.lexname, buff);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Keyword");
    }
    else if (isLogical(buff))
    {
        strcpy(t.lexname, buff);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Logical");
    }
    else if (isNumeric(buff))
    {
        strcpy(t.lexname, buff);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Numeric");
    }
    else if (isIdentifier(buff))
    {
        strcpy(t.lexname, buff);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Identifier");
    }
    else if (isLiteral(buff))
    {
        strcpy(t.lexname, buff);
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

int getSize(char *str)
{
    if (strcmp(str, "int") == 0)
        return sizeof(int);
    else if (strcmp(str, "float") == 0)
        return sizeof(float);
    else if (strcmp(str, "char") == 0)
        return sizeof(char);
    else if (strcmp(str, "double") == 0)
        return sizeof(double);
    else if (strcmp(str, "long") == 0)
        return sizeof(long);
}

int HASH(char *str)
{
    //Hashing based on first character
    char ch = str[0];
    if (str[0] == '_')
        return 26; //alphabets take till 25
    else if (str[0] >= 'A' && str[0] <= 'Z')
        return ch - 'A';

    return ch - 'a';
}

int SEARCH(char *str)
{
    int start = HASH(str);
    ListElement *ptr = TABLE[start];
    if (ptr == NULL)
        return 0;
    else
    {
        while (ptr != NULL)
        {
            if (strcmp(ptr->token.lexname, str) == 0)
                return 1;
            ptr = ptr->next;
        }
        return 0;
    }
}

void INSERT(Token tkn)
{
    if (SEARCH(tkn.lexname))
        return;
    int val = HASH(tkn.lexname);
    ListElement *cur = (ListElement *)malloc(sizeof(ListElement));
    cur->token = tkn;
    cur->next = NULL;

    if (TABLE[val] == NULL)
        TABLE[val] = cur;
    else
    {
        ListElement *temp = TABLE[val];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = cur;
    }
}