#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *write_the_value(void *value)
{
  int *p= (int *) value;
  printf("We read the value and its given as : %d\n", *p);
}


int main (int argc, char *argv[])
{
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  printf("This is our second to threads");
  pthread_t thread1[10];


  for (int i=0;i<10;i++)
  {

    if(pthread_create(&thread1[i],NULL,write_the_value,&arr[i])!=0)
    {
      printf("We couldnt create the thread\n");
      exit(1);
    }
    sleep(1);
  }

  for (int i=0;i<10;i++)
  {
    pthread_join(thread1[i],NULL);
  }



  return 0;

}
