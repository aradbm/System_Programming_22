#include <stdio.h>
#include "NumClass.h"
int main(){
	int a;
	int b; 
	printf("Enter 2 integer numbers:\n");
	if(scanf("%d%d",&a,&b)!=2)
	{
	printf("\nError! Give 2 integer numbers!");
	}
	else
	{
	printf("The Armstrong numbers are:");
	for(int i=a;i<=b; i++)
	{
		if(isArmstrong(i)==1)
		printf(" %d",i);
	}
	printf("\nThe Palindrome are:");
	for(int i=a;i<=b; i++)
	{
		if(isPalindrome(i)==1)
		printf(" %d",i);
	}
	printf("\nThe Prime numbers are:");
	for(int i=a;i<=b; i++)
	{
		if(isPrime(i)==1)
		printf(" %d",i);
	}
	printf("\nThe Strong numbers are:");
	for(int i=a;i<=b; i++)
	{
		if(isStrong(i)==1)
		printf(" %d",i);
	}
	}
	return 0;
}
