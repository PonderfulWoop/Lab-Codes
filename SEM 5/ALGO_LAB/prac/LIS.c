#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int max_from(int a[], int b){
	int max = INT_MIN;
	for(int i = 0; i<b; i++)
		if(a[i]>max)
			max = a[i];

	return max;
}

int LIS(int arr[], int n){
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i<n; i++){
		dp[i] = 1;
		for(int j = 0; j<i; j++){
			if(arr[i]>arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	return max_from(dp, n);
}

int main(){

	int x[] = {10, 2, 15, 22, 1};

	printf("%d", LIS(x, 5));
}