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
    if (!strcmp(str, "+") || !strcmp(str, "<-"))
        return 1;
    return 0;
}

int isLiteral(char str[])
{
    if (str[0] == '"' && str[strlen(str) - 1] == '"')
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

int isKeyword(char str[])
{
    if (!strcmp(str, "class") || !strcmp(str, "string") || !strcmp(str, "int"))
        return (1);
    return (0);
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
    else if (!strcmp(buff, ":"))
        return 1;
    else if (!strcmp(buff, "{"))
        return 1;
    else if (!strcmp(buff, "}"))
        return 1;
    else if (!strcmp(buff, "["))
        return 1;
    else if (!strcmp(buff, "]"))
        return 1;
    else if (!strcmp(buff, "."))
        return 1;
    return 0;
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
    char *delim = " +-*/,.;:><=()[]{}$\n";
    int len = strlen(delim);
    for (int i = 0; i < len; i++)
        if (c == delim[i])
            return 1;
    return 0;
}

Token getNextToken(char lexname[], int row, int col)
{
    Token t;
    if (lexname[0] == '\0')
    {
        t.row = -1;
    }
    else if (isArith(lexname))
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Arithmetic");
    }
    else if (isKeyword(lexname))
    {
        strcpy(t.lexname, lexname);
        t.row = row;
        t.col = col;
        strcpy(t.type, "Keyword");
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