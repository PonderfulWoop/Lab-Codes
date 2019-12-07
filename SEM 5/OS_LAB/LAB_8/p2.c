// Solution to reader-writer problem

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int counter = 0;

sem_t mutex, wrt;
int readcount;

void *reader(void *arg)
{
  sem_wait(&mutex);
  readcount++;
  if(readcount == 1)
    sem_wait(&wrt);
  sem_post(&mutex);

  printf("Reading counter: %d ", counter);

  sem_wait(&mutex);
  readcount--;
  if(readcount == 0)
    sem_post(&wrt);
  sem_post(&mutex);
}

void *writer(void *arg)
{
    sem_wait(&wrt);
    counter++;
    sem_post(&wrt);
}

int main()
{
  pthread_t t1, t2;

  sem_init(&mutex, 0, 1);  
  sem_init(&wrt, 0, 1);
  readcount = 0;

  pthread_create(&t2, NULL, reader, NULL);
  pthread_create(&t1, NULL, writer, NULL);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}
