//Program to remove comments
#include <stdio.h>

int main(){
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen("temp.c", "r");
	fb = fopen("temp_out.c", "w");
	ca = getc(fa);
	while(ca != EOF){
		if(ca == '/'){
			cb = getc(fa);
			if(cb == '/'){
				while(ca != '\n')
					ca = getc(fa);

			}
			else if(cb == '*'){
				do{
					while(ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				}while(ca != '/');
			}
			else{
				putc(ca, fb);
			}
		}
		else{
			putc(ca, fb);
		}
		ca = getc(fa);
	}

	fclose(fa);
	fclose(fb);

	return 0;
}