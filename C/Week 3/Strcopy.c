#include <stdio.h>

void copyStr(char s1[], char s2[]){
	static int i = 0;
	if(s1[i] == '\0'){
		s2[i] = '\0';
		return;
	}
	else{
		s2[i] = s1[i];
		i++;
		copyStr(s1, s2);
	}
}

int main(){
	char str1[100], str2[100];
	printf("Enter the String:\n");
	gets(str1);
	copyStr(str1, str2);
	printf("\nCopied String:\n");
	printf("%s\n", str2);
}