#include <iostream>
#include <stack>

int main()
{
	int k;
	std::stack<int> dataStack;
	std::cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int x;
		std::cin >> x;
		if (x)
		{
			dataStack.push(x);
		}
		else
		{
			dataStack.pop();
		}
	}
	int sum = 0;
	while (!dataStack.empty())
	{
		int x = dataStack.top();
		sum += x;
		dataStack.pop();
	}
	std::cout << sum << std::endl;
	return 0;
}