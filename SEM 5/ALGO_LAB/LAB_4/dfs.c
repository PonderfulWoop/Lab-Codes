#include<stdio.h>
#include <stdlib.h>

int a[20][20],reach[20],n;

void dfs(int v) {
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
	  if(a[v][i] && !reach[i]) {
		printf("pushing: %d\n", i);
		dfs(i);
		printf("popping: %d\n", i);
	}
}
void main() {
	int i,j,count=0;
	printf("Enter number of vertices:\n");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		reach[i]=0;
	}
	printf("Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	printf("pushing: %d\n", 1);
	dfs(1);
	printf("popping: %d\n", 1);
	for (i=1;i<=n;i++) {
		if(reach[i])
		   count++;
	}
	if(count==n)
	  printf("Graph is connected. \n");
	else
	  printf("Graph is not connected. \n");
}