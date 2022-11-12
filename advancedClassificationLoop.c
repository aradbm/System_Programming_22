#include <stdio.h>
int tripleNum(int p)
{
 return p*p*p;
}
int getLength(int p)
{
	int len=1;
	while(p>9)
	{
	l++;
	value/=10;
	}
	return len;
}
int isPalindrome(int p)
{
	int ans=1;
	int temp=p;
	int backwards=p;
	int len = getLength(p);
	while(len!=0)
	{
		int x = temp%10;
		backwards= x*;
		a=a/10;
	}
	if(a!=p)
		ans=0;
	return ans;
}
int isArmstrong(int p)
{
	int ans=1;
	int a = p;
	int sum=0;
	while(a!=0)
	{
		int x = tripleNum(a%10);
		sum=sum+x;
		a=a/10;
	}
	if(sum!=p)
		ans=0;
	return ans;
}
