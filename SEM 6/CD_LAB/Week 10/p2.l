%{
	int words = 0;
	int characters = 0;
	int blanks = 0;
	int lines = 0;
%}

%%
[a-zA-Z]+ {words++; characters+= strlen(yytext);}
\n {characters++; lines++;}
" " {blanks++; characters++;}
. {characters++;}
%%

int yywrap(){
	return 1;
}

int main(){
	printf("String:\n");
	yylex();
	printf("Words: %d\nCharacters: %d\nBlanks: %d\nLines: %d\n", words, characters, blanks, lines);
	return 0;
}