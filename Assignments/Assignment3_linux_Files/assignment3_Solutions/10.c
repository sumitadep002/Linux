//10. Write a program to print your name and surname in a file. Print the file descriptor, message and number of bytes written.

//to use write()
#include<unistd.h>


//to use open()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include<string.h>
#include<stdio.h>

int main()
{
int number_bytes=0,file;

file=open("10.txt",O_CREAT|O_RDWR|O_TRUNC);
if(file==-1)
{
perror("Erro while opening file");
}
else
{

char name_surname[30];

printf("enter the name:");
scanf("%s",name_surname);

number_bytes=write(file,&name_surname,strlen(name_surname));

printf("\nenter your surname:");
scanf("%s",name_surname);

number_bytes = write(file,&name_surname,strlen(name_surname)) + number_bytes;

printf("\nfile descriptor: %d\n",file);
printf("number of bytes written successfully: %d\n",number_bytes);
}

close(file);
return 0;

}
