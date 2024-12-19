#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int sig) {
    printf("child with PID = %d received signal %d (SIGUSR1) from parent with PID = %d\n", getpid(), SIGUSR1, getppid());
}

int main() {
    pid_t pid;

    pid = fork();


    
    if(pid < 0) { //error
        perror("fork");
        exit(EXIT_FAILURE);
    } else if(pid == 0){ //child
        
        if(signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
            perror("signal");
            exit(EXIT_FAILURE);
        }
        printf("child process with PID = %d waiting for signal from parent with PID = %d\n",getpid(), getppid());
        while(1){
            pause(); // wait for signal
        }
    }else { //parent
    
        printf("parent with PID = %d, sending signal to child with PID = %d...\n", getpid(), pid);
        
        sleep(2); //sleep for a bit before sending signal
        
        if(kill(pid, SIGUSR1) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }
        
        printf("Parent sent SIGUSR1 to child\n");
        
        sleep(1);
        
        if(kill(pid, SIGKILL) == -1){
            perror("kill");
            exit(EXIT_FAILURE);
        }
        
        printf("Child process terminated");
    }
    
    return 0;
        
}
