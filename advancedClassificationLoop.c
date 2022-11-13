#include <stdio.h>
int Pow(int a,int b)
{
	int num = 1;
	for(int i=0;i<b;i++)
	{
		num*=a;
	}
	return num;
}
int getLength(int p)
{
	int len=1;
	while(p>9)
	{
		len=len+1;
		p=p/10;
	}
	return len;
}
int isPalindrome(int p)
{
	int backwards=0;
	int temp=p;
	int len = getLength(p)-1;
	while(len>=0)
	{
		int x = temp%10;
		backwards+= x*Pow(10,len);
		temp=temp/10;
		len--;
	}
	if(backwards!=p)
		return 0;
	return 1;
}
int isArmstrong(int p)
{
	int a = p;
	int sum=0;
	while(a!=0)
	{
		int x = Pow(a%10,3);
		sum=sum+x;
		a=a/10;
	}
	if(sum!=p)
		return 0;
	return 1;
}
