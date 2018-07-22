#include <stdio.h>
#include <unistd.h>

int main(){

	int pd[2]; //pipe descriptor

	pipe(pd);

	if(fork() == 0){
		//close() file descriptor, so that it no longer refers to any file and may be reused

		close(1); //stop writing

		//dup(int oldfd);
		//dup() is a system call that allow us to change file descriptor
		//dup2(int oldfd, int newfd);
		//dup3(int oldfd, int newfd, int flags)
		//dup(pd[1]) creates a copy of the pipe descriptor
		dup(pd[1]); //the output is now sent to pipe

		close(pd[0]); // we are not going to read from pipe
		execlp("ls","ls","-l",NULL);
		//child
	}else{
		close(0); //stop reading
		
		dup(pd[0]); //the input in now recvd from pipe
		close(pd[1]); //we are not going to write to the pipe
		//parent
		execlp("wc","wc","-l",NULL);
	}

	return 0;
}