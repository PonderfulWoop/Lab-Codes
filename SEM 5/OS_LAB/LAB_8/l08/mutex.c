#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
volatile int counter = 0;

void *count(void *param)
{
  int *tid = (int *) param;

  for (int i = 0; i < 100; i++)
  {
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Thread id - %d, Count = %i\n", *tid, counter);
    pthread_mutex_unlock(&mutex);
  }
}

int main()
{
  pthread_t t1, t2;

  pthread_mutex_init(&mutex, 0);
  
  pthread_create(&t1, 0, count, (void *)&t1);
  pthread_create(&t2, 0, count, (void *)&t2);

  pthread_join(t1, 0);
  pthread_join(t2, 0);

  pthread_mutex_destroy(&mutex);

  return 0;
}