#include <stdio.h>
int main(int argc, char *argv[], char *envp[]) {
  int i;
  
  for(i=0; i<argc; i++)
    printf("\t### %s (%d): %s\n",argv[0],i,argv[i]);
  for(i=0; envp[i]; i++)
    printf("\t=== %s\n",envp[i]);

  return 0;
}
