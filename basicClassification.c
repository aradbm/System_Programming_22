#include <stdio.h>

int isPrime(int p)
{
	int ans = 1;
	if(p==1||p==2)
		return 1;
	for(int i=2; i<ans/2;i++)
	{
		if(p%i==0)
			ans=0;
	}
	return ans;
}


int isStong(int p)
{
return 1;
}
