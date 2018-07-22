#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>

int main(){


	int var;

    // printf("var:%d\n",var);
    // fork() creates a new process child and parent(duplicate)
    // fork() return process-id 0 as child and other than 0 is parent
    // it is not known which pid runs first
	// if (fork() == 0){
	//  	//child
	//  	var = 5;
    //     for(int i =0; i<=3; i++){
    //         printf("child:%d\n",var);
    //     }
	// }else{
	//  	//parent
	//  	printf("parent:%d\n",var);

	// }
    
    int pid = fork(); //creating new process
    if(pid == 0)
    {
        printf("child:%d\n",pid);
    }
    else{
        //each time parent returns different pid
        printf("Parent:%d\n",pid);
    }

    for(int i=0; i<=4; i++){
        printf("%d\n",pid);
        wait(0);    //it waits for the first child to die
    }

    // wait();
    //waitpid(2);

 
//    printf("var:%d\n",var);
}

