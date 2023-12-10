#include<stdio.h>
void sort(int argc,int *argv){
int temp;
for(int i=0;i<argc-1;i++)
{
for(int j=0;j<argc-1-i;j++)
{

if(argv[j]>argv[j+1])
{
temp=argv[j];
argv[j]=argv[j+1];
argv[j+1]=temp;
}
}
}
}
