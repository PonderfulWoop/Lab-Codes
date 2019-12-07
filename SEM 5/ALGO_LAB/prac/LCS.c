#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int LCS(char x[], char y[], int l1, int l2){
	int dp[l1+1][l2+1];
	int i, j;

	for(i = 0; i<=l1; i++){
		for(j = 0; j<=l2; j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(x[i-1] == y[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[l1][l2];
}

int main(){
	char x[] = "AGGTAB";
	char y[] = "GXTXAYB";

	printf("%d", LCS(x,y,strlen(x), strlen(y)));
}