#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void bfs(
    vector<vector<int>> & data, 
    vector<vector<vector<int>>> & map,
    vector<vector<vector<bool>>> & visit,
    int startK,
    int n, int m
)
{
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    vector<tuple<int, int, int>> _queue, nextQueue;

    _queue.push_back({0, 0, startK});
    visit[0][0][startK] = true;

    while(true)
    {
        for(auto & e : _queue)
        {
            if(get<0>(e) == n-1 && get<1>(e) == m-1)
            {
                return;
            }
            
            for(int dir=0; dir<4; ++dir)
            {
                if(0 <= get<0>(e)+dx[dir] && get<0>(e)+dx[dir] < n && 0 <= get<1>(e)+dy[dir] && get<1>(e)+dy[dir] < m)
                {
                    if(data[get<0>(e)+dx[dir]][get<1>(e)+dy[dir]] == 1)
                    {
                        if(get<2>(e) == 0 && !visit[get<0>(e)+dx[dir]][get<1>(e)+dy[dir]][get<2>(e)+1])
                        {
                            visit[get<0>(e)+dx[dir]][get<1>(e)+dy[dir]][get<2>(e)+1] = true;
                            map[get<0>(e)+dx[dir]][get<1>(e)+dy[dir]][get<2>(e)+1] = map[get<0>(e)][get<1>(e)][get<2>(e)]+1;
                            nextQueue.push_back({get<0>(e)+dx[dir], get<1>(e)+dy[dir], get<2>(e)+1});
                        }
                    }
                    else if(!visit[get<0>(e)+dx[dir]][get<1>(e)+dy[dir]][get<2>(e)]) 
                    {
                        visit[get<0>(e)+dx[dir]][get<1>(e)+dy[dir]][get<2>(e)] = true;
                        map[get<0>(e)+dx[dir]][get<1>(e)+dy[dir]][get<2>(e)] = map[get<0>(e)][get<1>(e)][get<2>(e)]+1;
                        nextQueue.push_back({get<0>(e)+dx[dir], get<1>(e)+dy[dir], get<2>(e)});
                    }
                }
            }
        }
        if(nextQueue.empty()) break;

        _queue = nextQueue;
        nextQueue.clear();
    }
}

int main()
{
    int n, m;
    scanf("%d %d",&n, &m);
    getchar();

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
            ch = getchar();
            arr[i].push_back((int)(ch-'0'));
        }
        getchar();
    }

    if(arr[0][0] == 1)
    {
        dist[0][0][1] = 1;
        bfs(arr, dist, visit, 1, n, m);
    }
    else
    {
        dist[0][0][0] = 1;
        bfs(arr, dist, visit, 0, n, m);
    }
    

    int result, resultA, resultB;

    resultA = dist[n-1][m-1][0];
    resultB = dist[n-1][m-1][1];

    if(resultA == -1) result = resultB;
    else if(resultB == -1) result = resultA;
    else if(resultA<resultB) result = resultA;
    else result = resultB;
    
    printf("%d",result);

    return 0;
}