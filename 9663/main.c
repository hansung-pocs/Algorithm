#include <stdio.h>

#define ABS(x) (((x)<0)?(-(x)):(x))

typedef struct {
	int x;
	int y;
} pos;

int dfs(int x, int y, pos * parent, int n)
{
	int sum = 0;
	if (y == n) return 1;
	parent[y].x = x;
	parent[y].y = y;
	int check[16];
	for (int i = 0; i <= n; ++i)check[i] = 1;
	for (int i=1;i<=y;++i)
	{
		pos v = parent[i];
		int y_diff = ABS((y+ 1)-(v.y));
		check[v.x] = 0;
		if (v.x + y_diff <= n) check[v.x + y_diff] = 0;
		if (v.x - y_diff >= 1) check[v.x - y_diff] = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (check[i])
		{
			sum += dfs(i, y+1, parent, n);
		}
	}
	return sum;
}

int nQueen(pos * graph, int n)
{
	int sum = 0;
	if (n == 1) return 1;
	for (int i=0;i<n;++i)
	{
		pos e = graph[i];
		pos arr[16];
		sum += dfs(e.x, e.y, arr, n);
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	pos graph[16];
	int result = 0;
	for (int i = 1; i <= n; ++i)
	{
		graph[i - 1].x = i;
		graph[i - 1].y = 1;
	}
	result = nQueen(graph, n);
	printf("%d", result);
	return 0;
}