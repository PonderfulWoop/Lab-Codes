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
		a[i][1] = 1;
		pf++;
	}
	for(int i=n;i<m;i++){
		int check = 0;
		printf("For page request %d : ",req[i]);
			for(int j=0;j<n;j++){
				if(a[j][0]==req[i]){
					check=1;
					ph++;
					a[j][1] = 1;
					printf("Page hit!\n");
							printf("\nTABLE\n");
				for(int tk=0;tk<n;tk++){
				printf("Page : %d bit : %d\n",a[tk][0],a[tk][1]);
			}
					break;
				}
			}
			if(check==1)
				continue;
			else{
				printf("Page fault!\n");
				pf++;
				int iter2 = n;
				while(iter2>=0){
					if(a[iter%n][1]==1){
						a[iter%n][1] = 0;
						iter = (iter+1)%n;
						iter2--;
					}
					else{
						printf("Replacing %d with %d\n",a[(iter%n)][0],req[i]);
						a[(iter%n)][0] = req[i];
						a[iter%n][1] = 1;
						iter = (iter+1)%n;
						break;
					}
				}
				printf("\nTABLE\n");
				for(int tk=0;tk<n;tk++){
				printf("Page : %d bit : %d\n",a[tk][0],a[tk][1]);
			}
			}
	}
	printf("\nPage faults : %d\n",pf);
	printf("Page hits : %d\n",ph);
}