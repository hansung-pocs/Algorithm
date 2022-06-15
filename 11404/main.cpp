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
                dist[a-1][b-1] = c;
                isFound = true;
            }
        }
        if(!isFound) 
        {
            graph[a-1].push_back({b-1, c});
            dist[a-1][b-1] = c;
        }
    }

    for(int i=0;i<n;++i)
    {
        dist[i][i] = 0;
    }

    for(int i=0;i<n;++i)
    {

        int currentIndex = i;
        vector<bool> visited = vector<bool>(n, false);

        while(true)
        {
            visited[currentIndex] = true;
            int target = -1;
            for(auto & e : graph[currentIndex])
            {
                if(visited[e.first]) continue;
                if(dist[i][e.first] == -1 || dist[i][e.first] > dist[i][currentIndex] + e.second)
                {
                    dist[i][e.first] = dist[i][currentIndex] + e.second;
                }
            }

            for(int j=0;j<n;++j)
            {
                if(visited[j] || dist[i][j] == -1 ) continue;
                if(target == -1 || dist[i][j] < dist[i][target])
                {
                    target = j;
                }
            }

            if(target == -1) break;
            currentIndex = target;
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