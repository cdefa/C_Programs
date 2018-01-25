/***************DESCRIPTION************************
*This program creates a fork with a parent and two childs that will excecute the 'ls' command 
*from the program and pipe it into a 'sort' command displaying the files in alphabetical order
*
******************CERTIFICATION********************
*NAME: Carlos De Faria
*PID: 6050200
***************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//instance variables for fork and fd
  pid_t pid;
  pid = fork();
  int fd[2];

  
 if(pid < 0){ /* an error occurred */
    perror("fork failed");
    exit(-1);
}   else if(pid == 0){ /* child process */
		close(fd[0]);
		dup2(fd[1],1);
		execlp("/bin/ls","ls","-l",NULL); //excecution of 'ls' command
		printf("execlp failed\n");
		exit(-1);
	}else { /* parent process */
		close(fd[1]);
		dup2(fd[0],0);
		if(pid == 0) { /* child process inside of patent process*/
			close(fd[0]);
			dup2(fd[1],1);
			execlp("sort","sort",NULL); //excecution of 'sort' command
			printf("execlp failed\n");
			exit(-1);
		}
	} 

  return 0;
}
