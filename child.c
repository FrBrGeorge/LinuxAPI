#include <stdio.h>
int main(int argc, char *argv[]) {
  int i;
  
  for(i=0; i<argc; i++)
    printf("\t### %s (%d): %s\n",argv[0],i,argv[i]);

  return 0;
}
