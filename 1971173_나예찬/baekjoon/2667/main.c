#include <stdio.h>
#include <stdlib.h>
int arr[30][30];
int n;
int * danji;
int d = 0;
int tmp;
void func(int i, int ii)
{
	arr[i][ii] = -1;
	danji[d-1]++;
	if (i>0)
	{
		if(arr[i-1][ii] == 1)
		{
			func(i-1,ii);
		}
	}

	if (ii<n-1)
	{
		if(arr[i][ii+1] == 1)
		{
			func(i,ii+1);
		}
	}

	if (i<n-1)
	{
		if(arr[i+1][ii] == 1)
		{
			func(i+1,ii);
		}
	}

	if (ii>0)
	{
		if(arr[i][ii-1] == 1)
		{
			func(i,ii-1);
		}
	}
	return;
}

int main()
{
	int i, ii;
	scanf("%d",&n);
	danji = (int *)malloc(sizeof(int)*n*n);
	for(i=0;i<n*n;i++)
	{
		danji[i] = 0;
	}

	for(i=0;i<n;i++)
	{
		for(ii=0;ii<n;ii++)
		{
			scanf("%1d",&arr[i][ii]);
		}
	}
	for(i=0; i<n; i++)
	{
		for(ii=0;ii<n;ii++)
		{
			if (arr[i][ii] == 1)
			{
				d++;
				func(i,ii);
			}
		}
	}
	printf("%d\n",d);
	for(i=d;i>=0;i--)
	{
		for(ii=0;ii<i-1;ii++)
		{
			if(danji[ii+1]<danji[ii])
			{
				tmp = danji[ii];
				danji[ii] = danji[ii+1];
				danji[ii+1] = tmp;
			}
		}
	}
	for(i=0;i<d; i++)
	{
		printf("%d\n",danji[i]);
	}
}