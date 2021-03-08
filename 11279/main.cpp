#include <iostream>
#include <vector>
#include <cstdio>

template <typename t>
class MaxHeap{
	std::vector<t> datas;
public:
	void insert(t data)
	{
		size_t cur = datas.size();
		datas.push_back(data);
		while (cur>0 && datas[((cur + 1) / 2) - 1] < datas[cur])
		{
			std::swap(datas[((cur+1) / 2)-1], datas[cur]);
			cur = ((cur + 1) / 2) - 1;
		}
	}
	t * remove()
	{
		if (datas.empty()) return nullptr;
		t * returnData = new t(datas.front());
		std::swap(datas.front(), datas.back());
		datas.pop_back();
		size_t cur = 0;
		size_t max_size = datas.size();
		while (cur < max_size)
		{
			size_t next_cur = cur;
			for (int i = 1; i <= 2; ++i)
			{
				if (cur * 2 + i < max_size)
				{
					if (datas[next_cur] < datas[cur * 2 + i])
						next_cur = cur * 2 + i;
				}
			}
			if (next_cur != cur)
			{
				std::swap(datas[cur], datas[next_cur]);
				cur = next_cur;
			}
			else
				break;
		}
		return returnData;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	MaxHeap<int> rootNode;

	for (int i = 0; i < n; ++i)
	{
		int operation;
		scanf("%d", &operation);
		if (operation)
			rootNode.insert(operation);
		else
		{
			int * data = rootNode.remove();
			if (data)
			{
				printf("%d\n", *data);
				delete data;
			}
			else
				printf("0\n");
		}
	}

	return 0;
}