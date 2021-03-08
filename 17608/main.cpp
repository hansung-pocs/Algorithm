#include <iostream>
#include <stack>

using namespace std;


int main()
{
	stack<int> dataStack;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		dataStack.push(x);
	}

	int biggest = -1;
	int count = 0;
	while (!dataStack.empty())
	{
		int x = dataStack.top();
		if (biggest < x)
		{
			biggest = x;
			++count;
		}
		dataStack.pop();
	}
	cout << count << endl;

	return 0;
}