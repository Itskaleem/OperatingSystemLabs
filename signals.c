#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void manager(int sig)
{
  if(sig==SIGUSR1)
  {
    printf("child: %d performed the SIGUSR1\n",getpid());
  }else
  {
  printf("parent: %d sent the signal\n",getpid());
  }

  return;
}

int main (void){
  printf("This programn will generate a singnal handler for SIGINT\n");

  int pid=fork();
  if(pid==0)
  {
    signal (SIGUSR1,manager);
    kill(getpid(),SIGUSR1);
  }else{
   signal (SIGUSR2,manager);
   kill(getpid(),SIGUSR2);
  }


  return 0;
}
