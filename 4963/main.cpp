#include <iostream>

using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

void dfs(int ** map, int i, int j, int m, int n)
{
    map[i][j] = -1;
    for(int ii=0;ii<8;++ii)
    {
        if(i+dy[ii]<0 || j+dx[ii]<0) continue;
        if(i+dy[ii]>=m || j+dx[ii]>=n) continue;
        if(map[i+dy[ii]][j+dx[ii]] == 1)
            dfs(map,i+dy[ii],j+dx[ii],m,n);
    }

}

int totalCount(int ** map, int m, int n)
{
    int sum = 0;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(map[i][j] == 1)
            {
                dfs(map, i, j, m, n);
                ++sum;
            }
        }
    }
    return sum;
}

int main()
{
    int ** map;
    int w,h;
    do
    {
        cin >> h >> w;
        map = new int*[w];
        for(int i=0;i<w;++i)
        {
            map[i] = new int[h];
            for(int j=0;j<h;++j)
            {
                cin >> map[i][j];
            }
        }
        if(w||h)
            std::cout << totalCount(map, w, h) << std::endl;
    }while(w||h);
    return 0;
}