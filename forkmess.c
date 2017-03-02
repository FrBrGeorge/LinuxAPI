#include <unistd.h>
#include <stdio.h>

int main() {
  int i;
  pid_t p;

  p = fork();
  for(i=0; i<100; i++)
    printf("%d %s\n", p, p ? "parent":"child");

  pause();
}
