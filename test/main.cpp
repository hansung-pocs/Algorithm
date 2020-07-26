#include <iostream>

int main()
{
	/*int ** map;
	int n;
	std::cin >> n;
	map = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		map[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			map[i][j] = i * n + j;
		}
	}*/
	int map[5][5] = {
		{1,223,356,24,2565},
		{21,245,673,74,345},
		{31,256,334,8654,95},
		{41,242,345,234,85},
		{51,52,53,54,55},
	};


	for (int (*ptr)[5] = map; ptr < map + 5; ++ptr)
	{
		for (int * pptr = *ptr; pptr < *ptr + 5; ++pptr)
		{
			std::cout << *pptr << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}