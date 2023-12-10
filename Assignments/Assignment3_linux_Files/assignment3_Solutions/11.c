//11. Print “hello world” from the program without use any printf or cout function.

#include<unistd.h>

int main()
{
write(1,"Hello World",11);
return 0;
}
