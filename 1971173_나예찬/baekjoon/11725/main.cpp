#include <iostream>
#include <vector>

using namespace std;

void DFS(
    vector<vector<int>> & tree,
    vector<int> & parent,
    vector<bool> & visit,
    int currentIndex
)
{
    visit[currentIndex] = true;

    for(auto & e : tree[currentIndex])
    {
        if(visit[e]) continue;
        parent[e] = currentIndex;
    }
    for(auto & e : tree[currentIndex])
    {
        if(visit[e]) continue;
        DFS(tree, parent, visit, e);
    }
}

int main()
{
    int n;

    scanf("%d",&n);

    vector<vector<int>> tree = vector<vector<int>>(n, vector<int>(0));

    vector<int> parent = vector<int>(n, -1);
    vector<bool> visit = vector<bool>(n, false);
    
    for(int i=0;i<n-1;++i)
    {
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }

    DFS(tree, parent, visit, 0);

    for(int i=1;i<n;++i)
    {
        printf("%d\n",parent[i]+1);
    }

    return 0;
}