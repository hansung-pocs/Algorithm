#include <iostream>
#include <vector>
#include <queue>

void DFS(std::vector<std::vector<bool>> & graph, std::vector<bool> & isVisited, int n, int max_n)
{
	std::cout << n << " ";
	isVisited[n] = true;
	for (int i = 1; i <= max_n; ++i)
	{
		if (graph[n][i])
		{
			if (!isVisited[i])
			{
				DFS(graph, isVisited, i, max_n);
			}
		}
	}
}

void BFS(std::vector<std::vector<bool>> & graph, std::vector<bool> & isVisited, int n, int max_n)
{
	std::queue<int> queue;
	queue.push(n);
	isVisited[n] = true;

	while (!queue.empty())
	{
		int top = queue.front();
		std::cout << top << " ";
		for (int i = 1; i <= max_n; ++i)
		{
			if (graph[top][i])
			{
				if (!isVisited[i])
				{
					isVisited[i] = true;
					queue.push(i);
				}
			}
		}
		queue.pop();
	}
}

int main()
{
	int n, m, v;
	std::cin >> n >> m >> v;
	std::vector<std::vector<bool>> isConnected(n+1, std::vector<bool>(n+1));
	std::vector<bool> isVisited(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		isConnected[a][b] = true;
		isConnected[b][a] = true;
	}

	DFS(isConnected, isVisited, v, n);
	std::cout << std::endl;
	isVisited = std::vector<bool>(n + 1);
	BFS(isConnected, isVisited, v, n);
	std::cout << std::endl;

	return 0;
}