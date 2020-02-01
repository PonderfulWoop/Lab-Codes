%{
	int pos = 0;
	int neg = 0;
	int pos_fl = 0;
	int neg_fl = 0;
%}

%%
-[0-9]+(\.)[0-9]+ {neg_fl++;}
[0-9]+(\.)[0-9]+ {pos_fl++;}
-[0-9]+ {neg++;}
[0-9]+ {pos++;}
%%

int yywrap(){
	return 1;
}

int main(){
	printf("String:\n");
	yylex();
	printf("Pos nums: %d\nNeg nums: %d\nPos fl: %d\nNeg fl: %d\n", pos, neg, pos_fl, neg_fl);
	return 0;
}