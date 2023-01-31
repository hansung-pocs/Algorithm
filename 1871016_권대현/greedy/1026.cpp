/*
https://www.acmicpc.net/problem/1026
*/
#include <iostream>
#include <algorithm>
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
  int total = 0;

  cin >> N;

  int A[N], B[N];
  for (int j = 0; j < N; j++)
  {
    cin >> A[j];
  }

  for (int j = 0; j < N; j++)
  {
    cin >> B[j];
  }

  sort(A, A + N, compare);
  sort(B, B + N);

  for (int i = 0; i < N; i++)
  {
    total += A[i] * B[i];
  }
  cout << total;

  return 0;
}