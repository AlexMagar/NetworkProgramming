#include <stdio.h>
#include <unistd.h>

int main(){
	
	int pd[2]; //pipe descriptor

	pipe(pd);

	if(fork() == 0){
		close(1);
		dup(pd[1]); //the output is now sent to pipe
		close(pd[0]); // we are not going to read from pipe
		execlp("ls","ls","-l",NULL);
		//child
	}else{
		close(0);
		dup(pd[0]); //the input in now recvd from pipe
		close(pd[1]); //we are not going to write to the pipe
		//parent
		execlp("wc","wc","-l",NULL);
	}

	return 0;
}