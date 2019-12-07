#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findGCD(int m, int n){
    if(n<m){
        int temp = n;
        n = m;
        m = temp;
    }
    
    int v = m;
    int gcd = 1;
    int opcount = 0;
    for(int i = 2; i<(int)sqrt(v); i++){
        opcount++;
        if(n%i == 0 && m%i == 0){
            while(n%i == 0 && m%i == 0){
                gcd = gcd * i;
                m = m/i;
                n = n/i;
                if(m == 0 || n == 0){
                    printf("Operation Count: %d\n", opcount);
                    return gcd;
                }
            }
        }
    }
    printf("Operation Count: %d\n", opcount);
    return gcd;
}

int main(){
    int m, n;
    printf("Enter two numbers: \n");
    scanf("%d%d", &m, &n);

    int ans = findGCD(m , n);

    printf("GCD = %d\n", ans);
}