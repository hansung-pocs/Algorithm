#include <iostream>
#include <ctime>

std::pair<int, int> getValue(int ** data, int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (data[i][j]) ++sum;
		}
	}
	if (sum == 0)
	{
		return { 1,0 };
	}
	else if (sum == size * size)
	{
		return { 0,1 };
	}
	else
	{
		std::pair<int, int> count;
		int ** _data;
		_data = new int*[size / 2];
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				_data = new int*[size / 2];
				for (int di = 0; di < size / 2; ++di)
				{
					_data[di] = new int[size / 2];
					for (int dj = 0; dj < size / 2; ++dj)
					{
						_data[di][dj] = data[size / 2 * i + di][size / 2 * j + dj];
					}
				}
				std::pair<int, int> result = getValue(_data, size / 2);
				count.first += result.first;
				count.second += result.second;
				for (int di = 0; di < size / 2; ++di)
				{
					delete[] _data[di];
				}
				delete[] _data;
			}
		}
		return count;
	}
}

int main()
{
	int ** img;
	int n;
	int tmp_n;
	int count = 0;
	scanf("%d", &n);
	srand(time(NULL));
	img = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		img[i] = new int[n];
	}
	tmp_n = n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			//scanf("%d", img[i] + j);
			img[i][j] = rand() % (rand() % 2 + 1);
		}
	}
	std::pair<int, int> value = getValue(img, n);
	printf("%d\n%d", value.first, value.second);
	return 0;
}