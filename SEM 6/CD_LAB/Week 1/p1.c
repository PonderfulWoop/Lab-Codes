#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fa, *fb;
	int ca;
	fa = fopen("temp.c", "r");
	fb = fopen("temp_out_p1.c", "w");

	ca = getc(fa);
	while(ca != EOF){
		if(ca == ' ' || ca == '\t'){
			putc(' ', fb);
			ca = getc(fa);
			while(ca == ' ' || ca == '\t')
				ca = getc(fa);
		}
		putc(ca, fb);
		ca = getc(fa);
	}
}