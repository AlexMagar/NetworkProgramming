#include <sys/socket.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
int main(){

		
	int socketvector[2]; //pair of socket descriptors
	socketpair(AF_LOCAL,SOCK_STREAM,0,socketvector);
	char readbuffer;

	if( fork() == 0){
		//child
		read(socketvector[0],&readbuffer,1);
		printf("Child: read %c \n",readbuffer );
		readbuffer = toupper(readbuffer);
		write(socketvector[0],&readbuffer,1);
		printf("Child: sent %c \n",readbuffer);
	}else{
		//parent
		write(socketvector[1],"b",1);
		printf("Parent: sent 'b' \n");
		read(socketvector[1],&readbuffer,1);
		printf("Parent: read %c \n", readbuffer);
		wait(NULL); /* wait for child to exit() */
	}