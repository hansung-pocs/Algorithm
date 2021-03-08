#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	int count_a, count_b;
	std::cin >> count_a >> count_b;

	std::string * arr_a, *arr_b;
	arr_a = new std::string[count_a];
	arr_b = new std::string[count_b];

	for (int i = 0; i < count_a; ++i)
		std::cin >> arr_a[i];

	for (int i = 0; i < count_b; ++i)
		std::cin >> arr_b[i];

	std::sort(arr_a, arr_a + count_a);
	std::sort(arr_b, arr_b + count_b);

	int index_a = 0, index_b = 0;
	std::vector<std::string> result_array;

	while (index_a < count_a && index_b < count_b)
	{
		if (arr_a[index_a] == arr_b[index_b])
		{
			result_array.push_back(arr_a[index_a]);
			++index_a;
			++index_b;
		}
		else if (arr_a[index_a] > arr_b[index_b])
		{
			++index_b;
		}
		else
		{
			++index_a;
		}
	}

	std::cout << result_array.size() << std::endl;
	for (std::string & element : result_array)
	{
		std::cout << element << std::endl;
	}
	

	return 0;
}