#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


int main (void)
{
    printf("Lets cread a pipe between parent and child\n");
    char c;
    int fd[2];
    if(pipe(fd)==0)
    {
        pid_t pid=fork();
        if(pid==0)
        {
            printf("I am child with pid: %d\n",getpid());
            close(fd[1]);
            int n=read(fd[0],&c,1);
            if(n==0)
            {
                printf("child was not able to read and the write descriptor is closed on other end\n");       
            }
            printf("Char passed %d is : %c\n",n,c);
        }else
        {
            printf("This is parent with pid: %d\n",getpid());
            close(fd[0]);
            c='A';
            int n=write(fd[1],&c,1);

        }

    }
    return 0;
}
