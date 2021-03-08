#include <stdio.h>

int arr[301][301];
int check[301][301];

void div_rr();

int check_div(int m, int n)
{
	int i,j,r=0;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if (arr[i][j]>0) check[i][j] = 1;
			else check[i][j] = 0;
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(check[i][j] > 0)
			{
				r++;
				div_rr(i,j,m,n);
				//check[i][j] = 0;
			}
		}
	}
	return r;
}

void div_rr(int i, int j, int m, int n)
{
	check[i][j] = 0;
	if(i>0 && check[i-1][j] > 0)
	{
		div_rr(i-1,j,m,n);
	}
	if(i<m && check[i+1][j] > 0)
	{
		div_rr(i+1,j,m,n);
	}
	if(j>0 && check[i][j-1] > 0)
	{
		div_rr(i,j-1,m,n);
	}
	if(j<n && check[i][j+1] > 0)
	{
		div_rr(i,j+1,m,n);
	}
}

void meltdown(int m, int n)
{
	int i, j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			check[i][j] = 0;
			if(i>0 && arr[i-1][j] == 0)
			{
				check[i][j]++;
			}
			if(i<m && arr[i+1][j] == 0)
			{
				check[i][j]++;
			}
			if(j>0 && arr[i][j-1] == 0)
			{
				check[i][j]++;
			}
			if(j<n && arr[i][j+1] == 0)
			{
				check[i][j]++;
			}
		}
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			arr[i][j] = 
				(arr[i][j] - check[i][j] > 0) ?
				(arr[i][j] - check[i][j]) : 0;
		}
	}
}

int main()
{
	int i, j;
	int m, n;
	int c=0, d;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	d=check_div(m,n);
	while(d<2)
	{
		meltdown(m,n);
		c++;
		if(d==0) {
			c=0;
			break;
		}
		d=check_div(m,n);
	}
	printf("%d",c);
}