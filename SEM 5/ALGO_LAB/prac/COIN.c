#include <stdio.h>
#include <stdlib.h>
int min(int a, int b){
	return (a<b)?a:b;
}
int findCount(int coins[], int amount, int n){
	int dp[amount+1];
	for(int i =0; i<=amount; i++)
		dp[i] = amount+1;

	dp[0] = 0;
	for(int i = 1; i<=amount; i++){
		for(int j = 0; j<n; j++){
			if(i>=coins[j]){
				dp[i] = min(dp[i], 1+dp[i-coins[j]]);
			}
		}
	}
	if(dp[amount]>amount)
		return -1;
	return dp[amount];
}

int main(){
	int coins[] = {1,2,5};
	int amount = 11;

	printf("%d\n", findCount(coins, amount, 3));
}