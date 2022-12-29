/*
https://www.acmicpc.net/problem/10162
*/
#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  int A = 300;
  int B = 60;
  int C = 10;
  int count = 0;

  cin >> T;

  if (T % C != 0)
    cout << -1;
  else
  {
    count = T / A;
    T = T % A;
    cout << count << " ";
    count = T / B;
    T %= B;
    cout << count << " ";
    count = T / C;
    cout << count << " ";
  }

  return 0;
}