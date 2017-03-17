#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define USE_PRINTF 0

int main(int argc, char **argv)
{
        int fd; /* file descriptor */
        pid_t pid; /* process identificator */
        char *file = "numbers.txt";
        char c;

        if (argc > 1)
                file = argv[1];

        sleep(2);
        write(1, "\n\n\n\n", 4);

        pid = fork(); /* next steps will be run in 2 different processes */

        if (pid == -1){
                perror("fork");
                return 1;
        }

        fd = open(file, O_RDONLY);

        if (fd == -1){
                perror("open");
                return 1;
        }


        while (read(fd, &c, 1) > 0)/* if read reaches end of file it returns 0 */
        {
                if (USE_PRINTF) {
                        printf("%i: %c, ", pid, c);
                } else {
                        write(1, &c, 1);
                }
                usleep(1);
        }

        if (USE_PRINTF) {
		printf("\n");
        } else {
        	write(1, "\n", 1);
        }
        close(fd);
        if (pid) pause();
        return 0;
}
