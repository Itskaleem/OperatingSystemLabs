#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int n;

void *read_the_value(void *value)
{
  printf("Please give us the interger value\n");
  scanf("%d", (int *)value );
}

void *write_the_value(void *value)
{
  sleep(5);
  int *p= (int *) value;
  printf("We read the value and its given as : %d\n", *p);
}


int main (int argc, char *argv[])
{
  printf("This is our first to threads");
  pthread_t thread1,thread2;

  if(pthread_create(&thread1,NULL,read_the_value,&n)!=0)
  {
    printf("we couldnt create the thread\n");
  }
  if(pthread_create(&thread2,NULL,write_the_value,&n)!=0)
  {
    printf("We couldnt create the thread\n");
  }

  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);

  return 0;

}
