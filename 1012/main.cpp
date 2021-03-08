#include <iostream>
#include <queue>

int data[50][50];

void paintArea(int i, int j, int i_max, int j_max)
{
	std::queue<std::pair<int,int>> needToPainted;
	needToPainted.push({ i,j });
	data[i][j] = 0;
	while (!needToPainted.empty())
	{
		std::pair<int,int> pos;
		pos = needToPainted.front();
		if (pos.first - 1 >= 0 && data[pos.first - 1][pos.second])
		{
			data[pos.first - 1][pos.second] = 0;
			needToPainted.push({ pos.first - 1,pos.second });
		}
		if (pos.second - 1 >= 0 && data[pos.first][pos.second - 1])
		{
			data[pos.first][pos.second - 1] = 0;
			needToPainted.push({ pos.first,pos.second - 1 });
		}
		if (pos.first + 1 < i_max && data[pos.first + 1][pos.second])
		{
			data[pos.first + 1][pos.second] = 0;
			needToPainted.push({ pos.first + 1,pos.second });
		}
		if (pos.second + 1 < j_max && data[pos.first][pos.second + 1])
		{
			data[pos.first][pos.second + 1] = 0;
			needToPainted.push({ pos.first,pos.second + 1 });
		}
		needToPainted.pop();
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int count = 0;
		for (int i = 0; i < 50; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				data[i][j] = 0;
			}
		}
		int n, m, k;
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; ++i)
		{
			int tmp_x, tmp_y;
			scanf("%d %d", &tmp_x, &tmp_y);
			data[tmp_y][tmp_x] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (data[i][j])
				{
					paintArea(i, j, n, m);
					++count;
				}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}