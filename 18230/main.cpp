#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>

int main()
{
	int n,a,b;
	std::cin >> n >> a >> b;

	int * arr = new int[n];
	std::vector<int> lstSmallTile;
	std::vector<int> lstBigTile;
	for (int i = 0; i < a; i++)
	{
		int iInput;
		std::cin >> iInput;
		lstSmallTile.push_back(iInput);
	}
	std::sort(lstSmallTile.begin(), lstSmallTile.end(), [](int a, int b) {return a > b;});
	for (int i = 0; i < b; i++)
	{
		int iInput;
		std::cin >> iInput;
		lstBigTile.push_back(iInput);
	}
	std::sort(lstBigTile.begin(), lstBigTile.end(), [](int a, int b) {return a > b;});

	int i = 0;
	for(int j : lstBigTile)
	{
		if (i <= n - 2)
		{
			arr[i] = j;
			arr[i + 1] = 1000001;
			i += 2;
		}
		else break;
	}
	int k=0;
	if (i != n)
	{
		for (; i < n; i++, k++)
		{
			arr[i] = lstSmallTile[k];
		}
	}
	for (i = n - 1; i > 0 && arr[i] != 1000001; i--)
	{

	}
	for (; i-1 >= 0 && k+1<(int)lstSmallTile.size(); i -= 2)
	{
		if (arr[i-1] < lstSmallTile[k] + lstSmallTile[k + 1])
		{
			arr[i-1] = lstSmallTile[k];
			arr[i] = lstSmallTile[k + 1];
			k += 2;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 1000001) sum += arr[i];
	}
	
	std::cout << sum << std::endl;
	return 0;
}