#include <iostream>
#include <vector>

using namespace std;

pair<int,int> getDeepest(vector<pair<int,int>> * graph, bool * visited, int index, int n)
{
	pair<int, int> deepest = {index, 0};
	visited[index] = true;
	for(pair<int,int> & itr : graph[index])
	{
		if(visited[itr.first]) continue;
		pair<int,int> result = getDeepest(graph, visited, itr.first, n);
		result.second += itr.second;
		if(result.second>deepest.second)
		{
			deepest = result;
		}
	}
	return deepest;
}

int main()
{
	int n;
	scanf("%d",&n);

	vector<pair<int,int>> * graph = new vector<pair<int,int>>[n];

	for(int i=0;i<n-1;++i)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u-1].push_back({v-1,w});
		graph[v-1].push_back({u-1,w});
	}

	bool * visited = new bool[n];

	pair<int,int> x =  getDeepest(graph,visited,0,n);
	for(int i=0;i<n;++i)
		visited[i] = false;
	pair<int,int> y = getDeepest(graph,visited,x.first,n);

	cout << y.second << endl;
	return 0;
}
