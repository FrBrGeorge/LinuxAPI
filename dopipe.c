#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
  int pipefd[2], res;
  pid_t pout, pin, pwait;

  pipe(pipefd);
  if (!(pout=fork())) {
    close(1);
    sleep(1);
    dup(pipefd[1]);
    close(pipefd[0]);
    execl("/usr/bin/cal", "cal", NULL);
  }
  close(pipefd[1]);
  printf("Writer: %d\n", pout);
  if(!(pin=fork())) {
    close(0);
    sleep(1);
    dup(pipefd[0]);
    execl("/usr/bin/rev", "rev", NULL);
  }
  close(pipefd[0]);
  printf("Reader: %d\n", pin);
  printf("Done %d\n", wait(&res));
  printf("Done %d\n", wait(&res));
  return 0;
}

