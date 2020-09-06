#include <iostream>
#include <deque>
#include <string>

int main()
{
	std::deque<int> deque;

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		std::string instruction;
		std::cin >> instruction;
		if (instruction == "push_front")
		{
			int value;
			scanf("%d", &value);
			deque.push_front(value);
		}
		else if (instruction == "push_back")
		{
			int value;
			scanf("%d", &value);
			deque.push_back(value);
		}
		else if (instruction == "pop_front")
		{
			if (!deque.empty())
			{
				printf("%d\n", deque.front());
				deque.pop_front();
			}
			else printf("-1\n");
		}
		else if (instruction == "pop_back")
		{
			if (!deque.empty())
			{
				printf("%d\n", deque.back());
				deque.pop_back();
			}
			else printf("-1\n");
		}
		else if (instruction == "size")
		{
			printf("%d\n", deque.size());
		}
		else if (instruction == "empty")
		{
			printf("%d\n", deque.empty());
		}
		else if (instruction == "front")
		{
			printf("%d\n", deque.empty() ? -1 : deque.front());
		}
		else if (instruction == "back")
		{
			printf("%d\n", deque.empty() ? -1 : deque.back());
		}
	}



	return 0;
}