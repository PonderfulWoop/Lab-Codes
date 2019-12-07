#include <stdio.h>
#include <stdlib.h>

int dp[1000];

int count(int k){
	if(k<0) return 0;
	if(k == 0) return 1;

	if(dp[k] != -1){
		return dp[k];
	}

	return dp[k] = count(k-1) + count(k-3) + count(k-5);
}

int main(){
	for(int i = 0; i<1000; i++)
		dp[i] = -1;
	int k = 6;
	printf("%d\n", count(k));
}