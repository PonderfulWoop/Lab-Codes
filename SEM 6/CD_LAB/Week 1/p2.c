#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fa, *fb;
	int ca;
	int flag = 0;
	fa = fopen("temp.c", "r");
	fb = fopen("temp_out_p2.c", "w");

	ca = getc(fa);
	while(ca != EOF){
		if(ca == '#' && !flag){
			ca = getc(fa);
			if(ca == 'i'){
				while(ca != '\n')
				ca = getc(fa);
			}
			else{
			putc('#', fb);
		}
		}
		putc(ca, fb);
		ca = getc(fa);
		if(ca == ')')
			flag = 1;
	}
}
