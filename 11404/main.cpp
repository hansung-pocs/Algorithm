#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    vector<vector<pair<int, int>>> graph = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    vector<vector<int>> dist = vector<vector<int>>(n, vector<int>(n, -1));
    
    for(int i=0;i<m;++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        bool isFound = false;
        for(auto & e : graph[a-1])
        {
            if(e.first == b-1 && e.second > c)
            {
                e = {b-1, c};
                isFound = true;
            }
        }
        if(!isFound) graph[a-1].push_back({b-1, c});
    }

    for(int i=0;i<n;++i)
    {
        dist[i][i] = 0;
        vector<int> visitTarget, nextVisitTarget;
        vector<bool> visited = vector<bool>(n, false);
        
        visitTarget.push_back(i);

        while(true)
        {
            for(int & e : visitTarget)
            {
                if(visited[e]) continue;
                visited[e] = true;
                for(auto & e2 : graph[e])
                {
                    int newDist = dist[i][e] + e2.second;
                    if(dist[i][e2.first] == -1 || dist[i][e2.first] > newDist)
                    {
                        dist[i][e2.first] = newDist;
                    }
                    nextVisitTarget.push_back(e2.first);
                }
            }

            visitTarget = nextVisitTarget;
            if(visitTarget.empty()) break;
            nextVisitTarget.clear();
        }        
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(dist[i][j] == -1) dist[i][j] = 0;
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}