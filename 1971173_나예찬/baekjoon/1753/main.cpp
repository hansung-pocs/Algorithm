#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class compPair
{
public:
	bool operator()(pair<int,int> left, pair<int,int> right)
	{
		if(left.second!=right.second)
			return left.second > right.second;

		else return left.first > right.first;
	}
};

void dijkstra(int start, vector<pair<int, int>> * graph, int * distanceResult, int graphSize)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>, compPair> nextNode;
	bool * visited = new bool[graphSize];

	nextNode.push({start,0});

	for(int i=0;i<graphSize;++i)
	{
		visited[i] = false;
	}

	while(!nextNode.empty())
	{
		pair<int,int> current = nextNode.top(); 
		nextNode.pop();
		if(distanceResult[current.first]!=-1 && distanceResult[current.first]<current.second)
			continue;

		for(pair<int,int> & path : graph[current.first])
		{
			if(visited[path.first])
				continue;
			if(distanceResult[path.first] == -1 || 
				distanceResult[path.first] > path.second + distanceResult[current.first]){
				distanceResult[path.first] = path.second + distanceResult[current.first];
				nextNode.push({path.first, distanceResult[path.first]});
			}
		}
	}
	
	delete[] visited;
}

int main()
{
	int V, E, K;
	scanf("%d %d %d",&V,&E,&K);
	--K;
	vector<pair<int,int>> * graph = new vector<pair<int,int>>[V];

	for(int i=0;i<E;++i)
	{
		int u, v, w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u-1].push_back({v-1, w});
	}

	int * distanceInfo = new int[V];
	for(int i=0;i<V;++i)
	{
		distanceInfo[i] = -1+(i==K);
	}
	dijkstra(K, graph, distanceInfo, V);
	for(int i=0;i<V;++i)
	{
		if(distanceInfo[i] != -1)
			printf("%d\n",distanceInfo[i]);
		else
			printf("INF\n");
	}
	
	return 0;
}
