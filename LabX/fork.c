#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	pid_t ppid, pid1, pid2, pid3;
	//the actual parent id is: %d, but due to the shell creating a new parent process it will be ppid++ in the rest of the code\n",getppid());
	//i could explicitly set the parent pid before the loops though and then print it each time instead of calling getppid()");
	ppid = getpid();

	pid1 = fork();
	if(pid1 == 0) {
		printf("1st child process created with PID = %d\n", getpid());
		printf("this process's parent process has PID = %d\n", getppid());
		printf("\n %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n");
	} else {
		pid2 = fork();
		if(pid2 == 0) {
			printf("2nd child process created with PID = %d\n", getpid());
			printf("this process's parent process has PID = %d\n", getppid());
			printf("\n %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n");

		} else {
			pid3 = fork();
			if(pid3 == 0) {
				printf("3rd child process created with PID = %d\n", getpid());
				printf("this process's parent process has PID = %d\n", getppid());
				printf("\n %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n");
			} else {
				printf("parent process has PID = %d\n", ppid);
				printf("\n %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n");
			}
		}
	}


	return 0;

}
