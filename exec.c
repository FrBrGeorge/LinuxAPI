#include <unistd.h>
#include <stdio.h>

int main() {
  printf("\texec!\n");
  execl("child", "child", "parameters", "are", "cool", NULL);
  printf("Unreachable line\n");
}
