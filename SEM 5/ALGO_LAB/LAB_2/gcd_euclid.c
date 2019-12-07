#include <stdio.h>
#include <stdlib.h>

int findGCD_Euclid(int m, int n){
    int opcount = 0;

    while(n != 0){
        opcount++;
        int r = m%n;
        m = n;
        n = r;
    }
    printf("Operation Count: %d\n", opcount);
    return m;
}

int main(){
    int m, n;
    printf("Enter two numbers: \n");
    scanf("%d%d", &m, &n);

    printf("GCD = %d\n", findGCD_Euclid(m,n));
}