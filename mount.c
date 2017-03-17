#include <stdio.h>
#include <sys/mount.h>

int main(int argc, char *argv[]) {
  return mount(argv[1], argv[2], argv[3], 0, NULL);
}
