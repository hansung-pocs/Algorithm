#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool relaxation(
    vector<int> & dist, vector<tuple<int, int, int>> & nodes)
{
    bool updated = false;

    vector<int> newDist = dist;

    for(auto & node : nodes)
    {
        int startNodeDist = dist[get<0>(node)];
        int endNodeDist = dist[get<1>(node)];
        int cost = get<2>(node);

        if(startNodeDist == -999999) continue;

        if(startNodeDist + cost <= endNodeDist || endNodeDist == -999999)
        {
            updated = true;
            newDist[get<1>(node)] = startNodeDist + cost;
        }
    }

    dist = newDist;

    return updated;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=0;i<tc;++i)
    {
        int n, m, w;
        scanf("%d %d %d",&n,&m,&w);

        vector<int> dist = vector<int>(n, -999999);
        dist[0] = 0;

        vector<tuple<int, int, int>> nodes;

        for(int j=0;j<m;++j)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            nodes.push_back({e-1,s-1,t});
            nodes.push_back({s-1,e-1,t});
        }
        for(int j=0;j<w;++j)
        {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            nodes.push_back({s-1,e-1,-t});
        }

        for(int j=0;j<n-1;++j) relaxation(dist, nodes);
        bool result = !relaxation(dist, nodes);

        printf("%s\n",result?"YES":"NO");
    }
    return 0;
}