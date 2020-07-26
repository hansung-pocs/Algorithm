#include <iostream>
#include <vector>
#include <tuple>
#include <list>

std::vector<std::vector<int>> map;

int recursion(int m, int n)
{
	int depth = 0;
	std::list<std::tuple<int, int>> todo_list;
	int count = 0;

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] == 1)
				todo_list.push_back({ i, j });
		}
	}

	while (true)
	{
		count = todo_list.size();
		for (int i = 0; i < count; ++i)
		{
			std::tuple<int, int> pos = todo_list.front();
			todo_list.pop_front();
			map[std::get<0>(pos)][std::get<1>(pos)] = 2;

			for (int i = 0; i < 4; ++i)
			{
				int x = std::get<1>(pos) + dx[i];
				int y = std::get<0>(pos) + dy[i];
				if (x >= 0 && x < n && y >= 0 && y < m)
				{
					if (!map[y][x])
					{
						map[y][x] = 1;
						todo_list.push_back({ y,x });
					}
				}
			}
		}
		if (!todo_list.size())
		{
			break;
		}
		++depth;

	}

	bool isNotCompleted = false;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] == 0)
				isNotCompleted = true;

			if (isNotCompleted)
				break;
		}
		if (isNotCompleted)
			break;
	}
	if (isNotCompleted) return -1;
	else return depth;
}

int main()
{

	int m, n, max = 0;
	scanf("%d %d", &n, &m);
	map.resize(m);
	for (int i = 0; i < m; ++i)
	{
		map[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &map[i][j]);
			//map[i][j] = (rand() % 3) - 1;
		}
	}


	int days = recursion(m, n);

	printf("%d", days);




	return 0;
}