#include <stdio.h>
#include <stdlib.h>

int findGCD_minus(int m, int n){
    int opcount = 0;

    while(m != 0 || n != 0){
        opcount++;
        if (m>n){
            m = m - n;
        }
        else if(m<n){
            n = n - m;
        }
        else{
            printf("Operation Count (minus): %d\n", opcount);
            return m;
        }
    }
    printf("Operation Count (minus): %d\n", opcount);
    if(m>n)
        return m;
    else
        return n;
}

int main(){
    int m, n;
    printf("Enter two numbers: \n");
    scanf("%d%d", &m, &n);

    printf("GCD = %d\n", findGCD_minus(m,n));
}