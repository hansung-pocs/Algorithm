/*
https://www.acmicpc.net/problem/1931
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second)
  {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, startTime, endTime;
  int count = 0;
  vector<pair<int, int>> vp;
  pair<int, int> p;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> p.first >> p.second;
    vp.push_back(p);
  }

  sort(vp.begin(), vp.end(), compare);

  startTime = 0;
  endTime = 0;
  for (int i = 0; i < N; i++)
  {
    if (endTime <= vp.at(i).first)
    {
      startTime = vp.at(i).first;
      endTime = vp.at(i).second;
      count++;
    }
  }

  cout << count;

  return 0;
}