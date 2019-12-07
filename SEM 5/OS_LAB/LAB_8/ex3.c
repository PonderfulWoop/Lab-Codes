#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t semaphore;

void* fcntl(void* param){
    printf("Thread 1\n");
    sem_post(&semaphore);
}
void* fcntl2(void* param){
    sem_wait(&semaphore);
    printf("Thread 2\n");
}
int main(){
    pthread_t threads[2];
    sem_init(&semaphore, 0, 0);
    pthread_create(&threads[0], 0, fcntl, 0);
    pthread_create(&threads[1], 0, fcntl2, 0);

    pthread_join(threads[0], 0);
    pthread_join(threads[1], 0);

    sem_destroy(&semaphore);
}