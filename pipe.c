#include <stdio.h>
#include <unistd.h>


int main(){

    //pipe() creates unidericational data channel
	//pipefd is a descriptors that return two file descriptors refering to the ends of the pipe
    // pipefd[0] -> refers to the read end of the pipe
    // and pipefd[1] -> refer to the write end of the pipe
	//pipe() help to brige communicate between child process and parent process
	//which is disconnected from eachother

	
	int pipedescriptors[2]; //pair of pipe descriptors

	int MAXBUFSIZE = 32;
	char buffer[MAXBUFSIZE+1];
	
	pipe(pipedescriptors);
	
	if(fork() == 0){
    //child
	printf("Writing to pipe descriptor %d\n",pipedescriptors[1]);
    // write() allow us to communicate with other users, by copying lines from our terminal to theirs
    //write(int fd, void *buf, size_t count) taeks 3 argus.
    //it writes up to count bytes from the buffer pointed buf to the file referred to by files descriptor fd
	write(pipedescriptors[1],"test message", sizeof("test message"));

	}else{
		//parent
	printf("Reading from pipe descriptor %d\n",pipedescriptors[0]);
    //read() try to read bytes from the file descriptor into the buffer starting at buffer
	read(pipedescriptors[0],buffer,12);
	printf("read\" %s \" \n",buffer);


	}
	return 0;
}