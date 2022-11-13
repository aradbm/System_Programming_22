#include <stdio.h>
#include "NumClass.h"
int main(){
	int a;
	int b; 
	printf("enter first number:\n");
	scanf("%d",&a);

	printf("enter second number:\n");
	scanf("%d",&b);
	
	printf("\nPrime numbers betweern a and b:  ");
	// run from a to b on all numbers and check all functions
	for(int i=a;i<=b; i++)
	{
		if(isPrime(i)==1)
		printf("%d  ",i);
	}
	printf("\nArmstrong numbers betweern a and b:  ");
	for(int i=a;i<=b; i++)
	{
		if(isArmstrong(i)==1)
		printf("%d  ",i);
	}
	printf("\nStrong numbers betweern a and b:  ");
	for(int i=a;i<=b; i++)
	{
		if(isStrong(i)==1)
		printf("%d  ",i);
	}
	printf("\nPalindrome numbers betweern a and b:  ");
	for(int i=a;i<=b; i++)
	{
		if(isPalindrome(i)==1)
		printf("%d  ",i);
	}
	printf("\n");
    return 0;
}
