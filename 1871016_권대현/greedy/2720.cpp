/*
https://www.acmicpc.net/problem/2720
*/
#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, money;
  int count = 0;
  int arr[4] = {25, 10, 5, 1};

  cin >> T;

  for (int i = 0; i < T; i++)
  {
    cin >> money;

    for (int j = 0; j < 4; j++)
    {
      count = money / arr[j];
      cout << count << " ";
      money = money % arr[j];
    }
    cout << "\n";
  }

  return 0;
}