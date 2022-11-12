#include <stdio.h>
#include "NumClass.h"
int main(){
	int a;
	int b; 
	printf("enter first number:\n");
	scanf("%d",&a);

	printf("enter second number:\n");
	scanf("%d",&b);
	
	printf("\nPrime numbers betweern a and b:");
	// run from a to b on all numbers and check all functions
	for(i=a;i<=b; i++)
	{
		if(isPrime(i))
		printf(i);
	}
	printf("\nArmstrong numbers betweern a and b:");
	for(i=a;i<=b; i++)
	{
		if(isArmstrong(i))
		printf(i);
	}
	printf("\nStrong numbers betweern a and b:");
	for(i=a;i<=b; i++)
	{
		if(isStrong(i))
		printf(i);
	}
	printf("\nPalindrome numbers betweern a and b:");
	for(i=a;i<=b; i++)
	{
		if(isPalindrome(i))
		printf(i);
	}
	printf("\n");
    return 0;
}
