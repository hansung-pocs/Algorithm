#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	scanf("%d %d",&n,&m);

	int ** data, ** sum;
	data = (int **)malloc(sizeof(int*)*(n+1));
	sum = (int **)malloc(sizeof(int*)*(n+1));
	for(int i=0;i<=n;++i)
	{
		data[i] = (int *)malloc(sizeof(int)*(n+1)); 
		sum[i] = (int *)malloc(sizeof(int)*(n+1));
	}

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&data[i][j]);
			if(i==1 && j==1)
				sum[i][j] = data[i][j];
			else if(i==1)
				sum[i][j] += (data[i][j] + sum[i][j-1]);
			else if(j==1)
				sum[i][j] += (data[i][j] + sum[i-1][j]);
			else
				sum[i][j] += (data[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1]);
		}
	}

	for(int i=0;i<m;++i)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1==1 && y1==1)
		{
			printf("%d\n",sum[x2][y2]);
		}
		else if(x1==1)
		{
			printf("%d\n",sum[x2][y2] - sum[x2][y1-1]);
		}
		else if(y1==1)
		{
			printf("%d\n",sum[x2][y2] - sum[x1-1][y2]);
		}
		else
		{
			printf("%d\n",sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]);
		}
	}

	return 0;
}

