#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int visited[100001];

int here, there;
int bfs(int pos,int count) {
	
	

	queue<pair<int,int>> q;
	q.push({pos,count});
	while (!q.empty()) {
		int vertex = q.front().first;
		int cnt = q.front().second;
		if (vertex == there)return cnt;
		visited[vertex] = 1;
		q.pop();

		//세가지 테스트
		//X-1
		if (vertex - 1 >= 0 && visited[vertex - 1]==-1) {
			q.push({ vertex - 1,cnt + 1 });
			cout << vertex - 1 << " ";
		}//X+1
		if (vertex + 1 <= 100000 && visited[vertex + 1] == -1) {
			q.push({ vertex + 1,cnt + 1 });
			cout << vertex +1 << " ";
		}//2*x
		 if (vertex * 2 <= 100000 && visited[vertex * 2] == -1) {
			q.push({ vertex * 2,cnt + 1 });
			cout << vertex*2 << " ";
		}

	}
}

int main() {
	fill_n(visited, 100001, -1);
	
	cin >> here >> there;

	int res =bfs(here,0);
	cout << res;
}