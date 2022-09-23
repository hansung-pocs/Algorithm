#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		std::cout << a + b << "\n";
	}
	return 0;
}