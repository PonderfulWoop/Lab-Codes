#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    printf("Enter two numbers:\n");
    scanf("%d %d", &n, &m);
    int small = (n>m) ? m:n;
    int opcount = 0;
    for(int i = small; i>=1; i--){
        opcount++;
        if(n%i == 0 && m%i == 0){
            printf("%d\n", i);
            break;
        }
    }
    printf("Operation Count = %d", opcount);
}