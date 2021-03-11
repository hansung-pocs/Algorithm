#include <iostream>
#include <string>

using namespace std;

void select(int start, int end, int n, string str)
{
	if (n == 0)
	{
		cout << str << "\n";
		return;
	}
	for (int i = start; i <= end - n + 1; ++i)
		select(i+1, end, n - 1, str + to_string(i) + " ");
}

int main()
{
	int n, m;
	cin >> n >> m;
	select(1, n, m, "");
	return 0;
}
