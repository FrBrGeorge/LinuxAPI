#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[]) {
  int wstatus, e;
  pid_t p;

  for(e=0; envp[e]; e++)
    printf("=== %s\n", envp[e]);

  setenv("XYXY", "___SEE THIS__", 1);
  setenv("HOME", "Sweet Home", 1);
  p = fork();
  if(p) {
    printf("=0= (XYXY: %s, HOME: %s)\n", getenv("XYXY"), getenv("HOME"));
    wait(&wstatus);
    printf("\t*** Child exited with status %d\n", wstatus);
    pause();
  }
  else {
    printf("\t*** I'm a child\n");
    printf("=1= (XYXY: %s, HOME: %s)\n", getenv("XYXY"), getenv("HOME"));
    execl("childe", "childe", "I am a child",  NULL);
  }
  return 0;
}
