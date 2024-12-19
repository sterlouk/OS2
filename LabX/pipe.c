#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid;

	int fds[2];

	if(pipe(fds) == -1) {
		perror("pipe");
		return 1;
	}

	pid = fork();

	if(pid == 0) { //we are in the child process
		close(fds[1]);
		char buffer[100];
		read(fds[0], buffer, sizeof(buffer));
		printf("Message received by child: \"%s\", Printed by: %d\n",buffer, getpid());
		close(fds[0]);
		exit(0);
	} else if(pid > 0) { //we are in the parent process
		close(fds[0]);
		char message[] = "Hello bro!";
		write(fds[1], message, sizeof(message));
		printf("Message sent by parent: \"%s\", Printed by: %d\n",message, getpid());
		close(fds[1]);
	} else {
		perror("fork");
		return 1;
	}
}
