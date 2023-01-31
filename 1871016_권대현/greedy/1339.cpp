/*
https://www.acmicpc.net/problem/1339
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int a, int b)
{
  return a > b;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  string a[N];
  int arr[27] = {0};

  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < a[i].length(); j++)
    {
      arr[a[i][j] - 65] += pow(10., a[i].length() - (j + 1));
    }
  }

  sort(arr, arr + 27, compare);

  int i = 0;
  int j = 9;
  int sum = 0;
  while (arr[i] != 0)
  {
    sum += arr[i] * j;
    i++;
    j--;
  }
  cout << sum;

  return 0;
}