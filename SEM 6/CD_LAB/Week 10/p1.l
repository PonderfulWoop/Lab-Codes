%{
	int v = 0;
	int c = 0;
%}

%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
%%

int yywrap(){
	return 1;
}

int main(){
	printf("String:\n");
	yylex();
	printf("V: %d, C: %d", v, c);
	return 0;
}