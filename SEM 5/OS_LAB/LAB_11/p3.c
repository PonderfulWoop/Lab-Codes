#include<stdio.h>
#include<stdlib.h>
int main(){
	printf("Enter frame size\n");
	int n;
	scanf("%d",&n);
	int a[n][2];
	for(int i=0;i<n;i++){
		a[i][0]=-1;
		a[i][1]=-1;
	}
	int iter = 0;
	int pf = 0;
	int ph = 0;
	printf("Enter number of page requests\n");
	int m;
	scanf("%d",&m);
	int req[m];
	printf("Enter page request sequence\n");
	for(int i=0;i<m;i++)
		scanf("%d",&req[i]);
	for(int i=0;i<n;i++){
		a[i][0] = req[i];
		a[i][1] = i;
		pf++;
	}
	for(int i=n;i<m;i++){
		int check = 0;
		printf("For page request %d : ",req[i]);
			for(int j=0;j<n;j++){
				if(a[j][0]==req[i]){
					check=1;
					ph++;
					a[j][1] = i;
					printf("Page hit!\n");
					break;
				}
			}
			if(check==1)
				continue;
			else{
				printf("Page fault!\n");
				pf++;
				int max = -1;
				int maxidx = -1;
				for(int k=0;k<n;k++){
					int temp = i-a[k][1];
					if(temp>max){
						max = temp;
						maxidx = k;
					}
				}
				printf("Replacing %d with %d\n",a[maxidx][0],req[i]);
				a[maxidx][0] = req[i];
				a[maxidx][1] = i;
			}
	}
	printf("\nPage faults : %d\n",pf);
	printf("Page hits : %d\n",ph);
}
