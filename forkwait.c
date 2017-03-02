#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int wstatus;
  pid_t p;

  p = fork();
  if(p) {
    wait(&wstatus);
    printf("Child done, status %d\n", wstatus);
    pause();
  }
  else
    printf("I am a child\n");
    sleep(3);
  return 0;
}
