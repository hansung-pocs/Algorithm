#include <iostream>
#include <list>

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int * arr = new int[n];
		std::list<std::pair<int, int>> data;
		std::list<std::pair<int, int>> printed;
		for (int j = 0; j < n; ++j)
		{
			int k;
			scanf("%d", &k);
			data.push_back({ j,k });
		}
		
		while (!data.empty())
		{
			auto pos = data.begin();
			auto dend = data.end();
			bool isHighest = true;
			for (auto pos2 = pos; pos2 != dend; ++pos2)
			{
				if (pos2->second > pos->second)
				{
					isHighest = false;
					break;
				}
			}
			if (isHighest)
			{
				printed.push_back(*pos);
				data.erase(pos);
			}
			else
			{
				data.push_back(*pos);
				data.erase(pos);
			}
		}
		int cnt = 0;
		for (auto & dat : printed)
		{
			++cnt;
			if (dat.first == m)
			{
				printf("%d\n", cnt);
				break;
			}
		}
	}
	return 0;
}