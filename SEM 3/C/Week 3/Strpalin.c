#include <stdio.h>

int chkPalin(char s[], int low, int high){
	
	if(low>=high)
		return 0;
	else{
		if(s[low] != s[high]){
			
			return 1;
		}
		else{
			chkPalin(s, low+1, high-1);
		}
	}
}

int main(){
	char str[100];
	printf("Enter the String:\n");
	gets(str);
	int i = 0;
	
	while(str[i] != '\0'){
		
		i++;
	}
	
	if(chkPalin(str, 0, i-1) == 0)
		printf("\nPalindrome\n");
	else
		printf("\nNot a Palindrome\n");
}