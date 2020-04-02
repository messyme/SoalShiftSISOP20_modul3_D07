#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h> 
#include <sys/wait.h> 

int main () {
    int fd[2];
    pid_t p;

    int count = 0;

    if (pipe(fd)==-1){ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 
    
    p = fork();

    if (p < 0) 
	{ 
		fprintf(stderr, "fork failed" ); 
		return 1; 
	}

    // child process
    else if (p == 0){ 
        dup2(fd[0], 0);
        close(fd[1]);
        char *wc_arg[] = {"wc", "-l", NULL};
		execvp("wc", wc_arg);
    }

    // parent process
    else {  
        dup2(fd[1], 1);
        close(fd[0]);
        char *ls_arg[] = {"ls", NULL};
        execvp("ls", ls_arg);
    }
}