#include <pthread.h>
#include <stdio.h>

void* Thread_Code(void* param){
    printf("Inside thread\n");
}
int main(){
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int k = pthread_create(&thread, &attr, Thread_Code, 0);
    printf("%d\n", k);
    printf("In main thread\n");
}