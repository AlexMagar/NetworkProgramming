#include <sys/socket.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
int main(){

		
	int socketvector[2]; //pair of socket descriptors
	//socketpair(int domain, int type, int protocol, int sv[2])
	//socketpair() call creates an unnamed pair of connected sockets in the specified domain
	//of the specified type, and using the optionally specified protocol
	socketpair(AF_LOCAL,SOCK_STREAM,0,socketvector);
	char readbuffer;

	if( fork() == 0){
		//child
		read(socketvector[0],&readbuffer,1); //read 1 byte from buffer
		printf("Child: read %c \n",readbuffer ); //print "b" from the readbuffer
		readbuffer = toupper(readbuffer); //upper case
		write(socketvector[0],&readbuffer,1); //writes content containing on readbuffer of size 1 byte
		printf("Child: sent %c \n",readbuffer); //print "B"
	}else{
		//parent
		write(socketvector[1],"b",1); //write 1 byte "b" in buffer
		printf("Parent: sent 'b' \n");
		read(socketvector[1],&readbuffer,1); //now readbuffer is updated and reads buffer
		printf("Parent: read %c \n", readbuffer); //print "B"
		wait(NULL); /* wait for child to exit() */
	}
}