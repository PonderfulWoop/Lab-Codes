#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char c, buf[10];
	FILE *fp = fopen("temp.c", "r");
	c = fgetc(fp);
	while(c != EOF){
		int i = 0;
		buf[0] = '\0';
		if(c == '='){
			buf[i++] = c;
			c = fgetc(fp);
			if(c == '='){
				buf[i++] = c;
				buf[i] = '\0';
				printf("Relational op: %s\n", buf);
			}
			else{
				buf[i] = '\0';
				printf("Assignment op: %s\n", buf);
			}
		}
		else{
			if(c == '<' || c == '>' || c == '!'){
				buf[i++] = c;
				c = fgetc(fp);
				if(c == '='){
					buf[i++] = c;
				}
				buf[i] = '\0';
				printf("Relational operator: %s\n", buf);
			}
			else{
				buf[i] = '\0';
			}
		}
		c = fgetc(fp);
	}
}