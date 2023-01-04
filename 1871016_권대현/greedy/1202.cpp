#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 300001

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K, idx = 0;
  long long totalV = 0;
  pair<int, int> jewel[MAX];
  int bag[MAX];
  priority_queue<int> pq;

  cin >> N >> K;

  for (int i = 0; i < N; i++)
  {
    cin >> jewel[i].first >> jewel[i].second;
  }
  for (int i = 0; i < K; i++)
  {
    cin >> bag[i];
  }
  // 가방과 보석 모두 무게 기준 오름차순으로 정렬
  sort(jewel, jewel + N);
  sort(bag, bag + K);

  for (int i = 0; i < K; i++)
  /***
   * idx를 다시 초기화하게 되면 넣었던 보석이 다시 들어간다. 따라서 초기화하면 안된다.
   * 초기화하지 않아도 되는 이유는 어차피 가방, 보석 둘 다 무게 기준으로 오름차순 정렬했기 때문에
   * 다음에 올 가방에 들어갈 수 있는 보석은 이미 우선순위 큐에 들어가 있다. 따라서 더 들어갈 수 있는 보석만 추가로 넣어주면 된다.
   */
  {
    while (jewel[idx].first <= bag[i] && idx < N) // 넣을 수 있는 보석을 모두 우선순위 큐에 넣는다.
    {
      pq.push(jewel[idx].second);
      idx++;
    }
    if (!pq.empty())
    {
      totalV += pq.top(); // 우선순위 큐 안에 값중 가장 큰 값을 더한다.
      pq.pop();
    }
  }
  cout << totalV;
  return 0;
}