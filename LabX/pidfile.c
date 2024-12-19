#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	FILE *pidfile;
	pidfile = fopen("processes.txt", "w");

	if(pidfile == NULL) {
		perror("open");
		exit(EXIT_FAILURE);
	}

    pid_t pid;
	pid = fork();

	if(pid < 0) { //error
		perror("fork");
		fclose(pidfile);
		exit(EXIT_FAILURE);
	} else if(pid == 0) { //child
		fprintf(pidfile, "Child process PID = %d\n",getpid());
		printf("child process PID = %d added to pidfile\n", getpid());
		fclose(pidfile);
	} else { //parent
		fprintf(pidfile, "parent process PID = %d\n", getpid());
		printf("parent process PID = %d added to pidfile\n", getpid());
		fclose(pidfile);
		wait(NULL);
	}

    /***** tried some shi here (it went wrong but kinda got something, the file resets though??? wtf)
	while(1) {
		char answer;
		printf("Wanna add another process? (Y/N)\n");
		scanf("%c", &answer);
		if(answer == 'Y' || answer == 'y') {
			pid = fork();
			if(pid < 0) { //error
				perror("fork");
				fclose(pidfile);
				exit(EXIT_FAILURE);
			} else if(pid == 0) { //child
				fprintf(pidfile, "Child process PID = %d\n",getpid());
				printf("child process PID = %d added to pidfile\n", getpid());
				fclose(pidfile);
			} else { //parent
				fprintf(pidfile, "parent process PID = %d\n", getpid());
				printf("parent process PID = %d added to pidfile\n", getpid());
				fclose(pidfile);
				wait(NULL);
			}
		}else {
		    return 0;
		}
	}
	
	****/
    return 0;
}
