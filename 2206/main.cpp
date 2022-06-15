#include <iostream>
#include <vector>

using namespace std;

void dfs(
    vector<vector<int>> & data, 
    vector<vector<vector<int>>> & map,
    vector<vector<vector<bool>>> & visit,
    int i, int j, int k, 
    int n, int m
)
{
    int dx[] = {i+1, i-1, i, i};
    int dy[] = {j, j, j+1, j-1};

    visit[i][j][k] = true;

    for(int dir=0; dir<4; ++dir)
    {
        if(0 <= dx[dir] && dx[dir] < n && 0 <= dy[dir] && dy[dir] < m)
        {
            if(data[dx[dir]][dy[dir]] == 1)
            {
                if(k == 0 && !visit[dx[dir]][dy[dir]][k+1])
                {
                    map[dx[dir]][dy[dir]][k+1] = map[dx[dir]][dy[dir]][k]+1;
                    dfs(data, map, visit, dx[dir], dy[dir], k+1, n, m);
                }
            }
            else if(!visit[dx[dir]][dy[dir]][k]) 
            {
                map[dx[dir]][dy[dir]][k] = map[dx[dir]][dy[dir]][k]+1;
                dfs(data, map, visit, dx[dir], dy[dir], k, n, m);
            }
        }

    }
    
    visit[i][j][k] = false;
}

int main()
{
    int n, m;
    scanf("%d %d",&n, &m);

    vector<vector<int>> arr = vector<vector<int>>(n, vector<int>());

    vector<vector<vector<bool>>> visit = 
    vector<vector<vector<bool>>>(
        n, vector<vector<bool>>(
            m, vector<bool>(
                2, false
            )
        )
    );

    vector<vector<vector<int>>> dist = 
    vector<vector<vector<int>>>(
        n, vector<vector<int>>(
            m, vector<int>(
                2, -1
            )
        )
    );

    for(auto & e : arr) e.reserve(m);

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            char ch;
            scanf("%c",&ch);
            arr[i].push_back(ch);
        }
        getchar();
    }

    dist[0][0][0] = 0;
    dfs(arr, dist, visit, 0, 0, 0, n, m);

    int result, resultA, resultB;

    resultA = dist[n-1][m-1][0];
    resultB = dist[n-1][m-1][1];

    if(resultB == -1 || resultA < resultB) result = resultA;
    else result = resultB;
    
    printf("%d",result);

    return 0;
}