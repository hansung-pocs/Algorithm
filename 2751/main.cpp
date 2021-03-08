#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::vector<int> array;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		array.push_back(k);
	}

	std::sort(array.begin(), array.end());

	for (int i : array)
	{
		printf("%d\n", i);
	}

	return 0;
}