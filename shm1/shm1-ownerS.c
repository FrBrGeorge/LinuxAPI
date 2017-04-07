#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include<signal.h>

#define SHMEM_SIZE	4096
#define SH_MESSAGE	"Hello World!\n"

int flag = 0;

void sig_handler(int signo)
{
	printf("\nCathcing %d!\n", signo);
	flag = 1;
}

int main (void)
{
	int shm_id;
	char * shm_buf;
	int shm_size;
	struct shmid_ds ds;
	
	signal(SIGINT, sig_handler);

	shm_id = shmget (IPC_PRIVATE, SHMEM_SIZE, IPC_CREAT | IPC_EXCL | 0600);

	shm_buf = (char *) shmat (shm_id, NULL, 0);
	shmctl (shm_id, IPC_STAT, &ds);
	shm_size = ds.shm_segsz;
	strcpy (shm_buf, SH_MESSAGE);
	printf ("ID: %d\n", shm_id);

	pause();

	shmdt (shm_buf);
	shmctl (shm_id, IPC_RMID, NULL);
	printf("Done\n");

	return 0;
}
