#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void* retSum(void* params){
    int i = (int)params;
    int sum = 0;
    while(i>0){
        sum += i%10;
        i = i/10;
    }
    return (void*)sum;
}
void* mulSum(void* params){
    int i = (int)params;
    int mul = 1;
    while(i>0){
        mul = mul*(i%10);
        i = i/10;
    }

    return (void*)mul;
}
int main(){
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    
    pthread_t t, t2;
    pthread_create(&t, 0, retSum, (void*)n);
    pthread_create(&t2, 0, mulSum, (void*)n);
    int sum, mul;
    pthread_join(t, (void**)&sum);
    pthread_join(t2, (void**)&mul);

    printf("sum of digis: %d\n", sum);
    printf("Multiplication of digis: %d \n", mul);
}