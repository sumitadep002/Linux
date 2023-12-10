#include<stdio.h>
void factorial(){
int fact=1,n,prod=1;
printf("enter n :");
scanf("%d",&n);
for(int i=1;i<=n;i++)
fact=fact*i;
printf("\nfactorial of  %d  =%d",n,fact);
}
