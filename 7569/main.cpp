#include <iostream>
#include <vector>
#include <tuple>
#include <list>

std::vector<std::vector<std::vector<int>>> map;

int recursion(int m, int n, int o)
{
	int depth = 0;
	std::list<std::tuple<int, int, int>> todo_list;
	int count = 0;

	int dx[] = { 1,-1,0,0,0,0 };
	int dy[] = { 0,0,1,-1,0,0 };
	int dz[] = { 0,0,0,0,1,-1 };

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < o; ++k)
			{
				if (map[i][j][k] == 1)
					todo_list.push_back({ i, j, k });
			}
		}
	}

	while (true)
	{
		count = todo_list.size();
		for (int i = 0; i < count; ++i)
		{
			std::tuple<int, int, int> pos = todo_list.front();
			todo_list.pop_front();
			map[std::get<0>(pos)][std::get<1>(pos)][std::get<2>(pos)] = 2;

			for (int i = 0; i < 6; ++i)
			{
				int x = std::get<2>(pos) + dx[i];
				int y = std::get<1>(pos) + dy[i];
				int z = std::get<0>(pos) + dz[i];
				if (x >= 0 && x < o && y >= 0 && y < n && z >= 0 && z < m)
				{
					if (!map[z][y][x])
					{
						map[z][y][x] = 1;
						todo_list.push_back({ z,y,x });
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
			for (int k = 0; k < o; ++k)
			{
				if (map[i][j][k] == 0)
					isNotCompleted = true;

				if (isNotCompleted)
					break;
			}
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
	int m, n, o, max = 0;
	scanf("%d %d %d", &o, &n, &m);
	map.resize(m);
	for (int i = 0; i < m; ++i)
	{
		map[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			map[i][j].resize(o);
			for (int k = 0; k < o; ++k)
			{
				scanf("%d", &map[i][j][k]);
				//map[i][j] = (rand() % 3) - 1;
			}
		}
	}


	int days = recursion(m, n, o);

	printf("%d", days);




	return 0;
}