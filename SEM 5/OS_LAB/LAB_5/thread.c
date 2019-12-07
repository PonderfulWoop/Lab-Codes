#include <pthread.h>
#include <stdio.h>

void* Thread_Code(void* param){
    printf("Inside thread\n");
}
int main(){
    pthread_t thread;
    int k = pthread_create(&thread, NULL, Thread_Code, 0);
    printf("%d\n", k);
    printf("In main thread\n");
    //pthread_join(thread, 0);
}