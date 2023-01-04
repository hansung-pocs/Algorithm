/*
https://www.acmicpc.net/problem/1715
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int getValue()
{
  int value = pq.top();
  pq.pop();

  return value;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, inputV;
  int sum = 0, count = 0;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> inputV;
    pq.push(inputV);
  }

  if (N == 1)
  {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < N - 1; i++)
  {
    sum = getValue() + getValue();
    count += sum;
    pq.push(sum);
  }
  cout << count;
  return 0;
}