#include <stdio.h>
#include <stdlib.h>
char arr[120][120];
int n;
int d = 0;
int tmp;
void func(int i, int ii, char c)
{
	if (arr[i][ii] == 'R' || arr[i][ii] == 'G')
		arr[i][ii] = 'X';
	else if(arr[i][ii] == 'B')
		arr[i][ii] = 'V';
	else
		arr[i][ii] = 'A';

	if (i>0 && arr[i-1][ii] == c)
		{
			func(i-1,ii,c);
		}

	if (ii<n-1 && arr[i][ii+1] == c)
		{
			func(i,ii+1,c);
		}

	if (i<n-1 && arr[i+1][ii] == c)
		{
			func(i+1,ii,c);
		}

	if (ii>0 && arr[i][ii-1] == c)
		{
			func(i,ii-1,c);
		}
	return;
}

int main()
{
	int i, ii;
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
	}
	for(i=0; i<n; i++)
	{
		for(ii=0;ii<n;ii++)
		{
			
			if (arr[i][ii] == 'R')
			{
				d++;
				func(i,ii,'R');
			}
			else if (arr[i][ii] == 'G')
			{
				d++;
				func(i,ii,'G');
			}
			else if (arr[i][ii] == 'B')
			{
				d++;
				func(i,ii,'B');
			}
		}
	}
	printf("%d ",d);
	d=0;
	for(i=0; i<n; i++)
	{
		for(ii=0;ii<n;ii++)
		{
			if (arr[i][ii] == 'X')
			{
				d++;
				func(i,ii,'X');
			}
			else if (arr[i][ii] == 'V')
			{
				d++;
				func(i,ii,'V');
			}
		}
	}
	printf("%d",d);
}