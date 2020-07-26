#include <iostream>
#include <list>

int main()
{
	std::list<int> datas;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		datas.push_back(i+1);
	}

	while (1)
	{
		if (datas.size() == 1) break;
		datas.pop_front();
		datas.push_back(datas.front());
		datas.pop_front();
	}
	printf("%d", datas.front());



	return 0;
}