#include <iostream>
#include <vector>

using namespace std;

pair<int,int> getDeepest(vector<pair<int,int>> * tree, bool * isVisited, pair<int,int> currentData, pair<int,int> maxData)
{
	isVisited[currentData.first] = true;

	for(pair<int,int> & itr : tree[currentData.first])
	{
		
		if(isVisited[itr.first]) 
			continue;

					
		pair<int,int> data = getDeepest(
			tree, isVisited, 
			{itr.first, currentData.second+itr.second}, 
			maxData
		);


		if(maxData.second < data.second){
			maxData.first = data.first;
			maxData.second = data.second;
		}
	}

	return (currentData.second > maxData.second) ? currentData : maxData;

}

int main()
{
	int v;
	cin >> v;

	vector<pair<int,int>> * tree;
	tree = new vector<pair<int,int>>[v];

	for(int i=0;i<v;++i)
	{
		int t;
		cin >> t;
		int a, b;
		while(true){
			cin >> a;
			if(a==-1)
				break;
			cin >> b;
			tree[t-1].push_back({a-1, b});
		}
	}
	
	bool * visited = new bool[v];
	pair<int,int> deepest;
	
	for(int i=0;i<v;++i) 
		visited[i] = false;

	deepest = getDeepest(tree, visited, {0,0}, {0,0});

	for(int i=0;i<v;++i) 
		visited[i] = false;
	
	deepest = getDeepest(tree, visited, {deepest.first, 0}, {deepest.first,0});
	
	cout << deepest.second << endl;

	delete[] visited;
	delete[] tree;

	return 0;
}
