%{
	int printf_cnt = 0;
	int scanf_cnt = 0;
%}

%%
"scanf" {scanf_cnt++; fprintf(yyout, "READ");}
"printf" {printf_cnt++; fprintf(yyout, "WRITE");}
%%

int yywrap(){
	return 1;
}

int main(int argc, char **argv){	
	yyin = fopen(argv[1], "r");
	if(argc<2){
		printf("File missing: \n");
		exit(0);
	}
	yyout = fopen("out.c", "w");
	yylex();
	printf("\n");
	return 0;
}