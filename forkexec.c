#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int wstatus;
  pid_t p;

  p = fork();
  if(p) {
    setenv("a", "export", 1);
    wait(&wstatus);
    printf("\t*** Child exited with status %d\n", wstatus);
    pause();
  }
  else {
    sleep(1);
    printf("%s\n", getenv("a"));
    printf("\t*** I'm a child\n");
    execl("child", "child", "I am a child",  NULL);
  }
  return 0;
}
