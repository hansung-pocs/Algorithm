#include <stdio.h>

int main(){
	int pibo[50];
	int i,j=0, n, o, tmp;
	int div[50]={0,};
	int divr[50]={0,};
	int result= 1;

	pibo[0] = 0;
	pibo[1] = 1;

	scanf("%d",&n);
	scanf("%d",&o);

	for(i=2;i<=n+1;i++)
	{
		pibo[i] = pibo[i-1] + pibo[i-2];
	}
	i--;
	
	for(i=0;i<o;i++)
	{
		scanf("%d",&tmp);
		div[tmp] = 1;
	}

	for(i=1;i<=n;i++)
	{
		if(div[i]) j++;
		else divr[j]++;
	}
	
	for(i=0;i<=j;i++)
	{
		if(divr[i]!=0)result*=pibo[divr[i]+1];
	}
	printf("%d",result);
}