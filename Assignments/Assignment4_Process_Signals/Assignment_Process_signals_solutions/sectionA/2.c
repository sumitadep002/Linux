//2. What is the output of the following code?

//CODE:

#include <stdio.h> 
#include <unistd.h> 
int main() 
{ 

//every call of fork() system call will return the PID
    	if(fork() || fork())
    	fork();
 
	printf("1\n");
//    printf("%d\n",getpid()); 
    return 0; 
}

/*
Explantion:

	
Parent	:prints 1
	:(1)fork prints 1 and execute (3)fork() which will print 1
	:(2)fork prints 1 and execute (3)fork() which will print 1
		
		
*/
