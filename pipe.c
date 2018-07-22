#include <stdio.h>
#include <unistd.h>


int main(){
	
	int pipedescriptors[2]; //pair of pipe descriptors

	int MAXBUFSIZE = 32;
	char buffer[MAXBUFSIZE+1];
	
	pipe(pipedescriptors);
	
	if(fork() == 0){
		//child
	printf("Writing to pipe descriptor %d\n",pipedescriptors[1]);
	write(pipedescriptors[1],"test message", sizeof "test message");

	}else{
		//parent
	printf("Reading from pipe descriptor %d\n",pipedescriptors[0]);
	read(pipedescriptors[0],buffer,12);
	printf("read\" %s \" \n",buffer);


	}
	return 0;
}