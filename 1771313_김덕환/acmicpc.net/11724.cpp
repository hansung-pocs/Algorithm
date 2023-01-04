#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

void addEdge(vector<vector<int>>& graph, int& u, int& v) {
        graph[u - 1].push_back(v - 1);
}

void dfs(int n, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[n] = true;
    for (auto next : graph[n]) {
        if (not visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    vector<bool> visited(N, false);
    

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }

    int component = 0;
    for (int i = 0; i < N; i++) {
        if (not visited[i]) {
            dfs(i, graph, visited);
            component++;
        }
    }

    cout << component << endl;

    return 0;
}