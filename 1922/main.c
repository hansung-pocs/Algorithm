#include <stdio.h>
#include <stdlib.h>

typedef struct Path {
	int startNode;
	int endNode;
	int cost;
} Path;

Path nodes[100001];
int graph[1001];

int compare(const Path * first, const Path * second)
{
	return first->cost - second->cost;
}

int findRoot(int index)
{
	int result = index;
	while (graph[result])
	{
		result = graph[result];
	}
	return result;
}

void join(int indexA, int indexB)
{
	graph[indexB] = indexA;
}

int main()
{
	int n, m, sum=0;
	Path * itr = nodes + 1;

	scanf("%d %d", &n, &m);
	while (itr <= nodes + m)
	{
		scanf("%d %d %d", &itr->startNode, &itr->endNode, &itr->cost);
		++itr;
	}
	qsort(nodes + 1, m, sizeof(Path), compare);
	itr = nodes + 1;
	int joinCount = 0;
	while (itr <= nodes + m && joinCount < n-1)
	{
		int rootA = findRoot(itr->startNode);
		int rootB = findRoot(itr->endNode);
		if (!rootA || !rootB || rootA != rootB)
		{
			join(rootB, rootA);
			sum += itr->cost;
			++joinCount;
		}
		++itr;
	}
	printf("%d\n", sum);
	return 0;
}