#include <unistd.h>
#include <stdio.h>

int main() {
  execl("child", "child", "parameters", "are", "cool", NULL);
  printf("Unreachable line\n");
}
