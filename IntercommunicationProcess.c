#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int main (void)
{
  printf("THis is gonna be example of system call pipe for interprocess communication\n");

  char a='1';
  int file[2];
  pipe(file);
  pid_t pid = fork();
  if(pid==0)
  {
    printf("I am child and I am gonna accept everything that my dad passes to me\n");
    close(file[1]);
    sleep(10);
    int nw=0;
    for(int i=0;i<10;i++)
    {
      int n = read(file[0],&a,1);
      nw= n+nw;
      printf("%d:\t %c\n", nw, a);
    }


  }else
  {
    close(file[0]);
    for(int i=0;i<10;i++)
    {
      int n= write(file[1], &a, 1);
      a = a + 'a';
    }

  }


  return 0;
}
