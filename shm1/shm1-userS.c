#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv)
{
	int shm_id;
	char * shm_buf;
	
	shm_id = atoi (argv[1]);
	shm_buf = (char *) shmat (shm_id, 0, 0);
	printf ("Message: %s\n", shm_buf);
	shmdt (shm_buf);

	return 0;
}
