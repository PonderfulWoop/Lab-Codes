%{
	int cnt = 0;
%}

%%
"and" {cnt++;}
"or" {cnt++;}
"but" {cnt++;}
%%

int yywrap(){
	return 1;
}

int main(int argc, char **argv){
	printf("String:\n");
	yylex();
	if(cnt > 0)
		printf("Compound\n");
	else
		printf("Simple\n");
	return 0;
}