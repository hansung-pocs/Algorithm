#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	std::cin.ignore();
	for (int i = 0; i < T; ++i)
	{
		std::stack<char> lChar;
		std::stack<char> rChar;
		while (true)
		{
			char ch = std::cin.get();
			if (ch == '\n') break;
			else if (ch == '<')
			{
				if (!lChar.empty())
				{
					char tmp = lChar.top();
					rChar.push(tmp);
					lChar.pop();
				}
			}
			else if (ch == '>')
			{
				if (!rChar.empty())
				{
					char tmp = rChar.top();
					lChar.push(tmp);
					rChar.pop();
				}
			}
			else if (ch == '-')
			{
				if (!lChar.empty())
				{
					lChar.pop();
				}
			}
			else
			{
				lChar.push(ch);
			}
		}
		while (!lChar.empty())
		{
			char tmp = lChar.top();
			lChar.pop();
			rChar.push(tmp);
		}
		std::string result;
		while (!rChar.empty())
		{
			result+=rChar.top();
			rChar.pop();
		}
		std::cout << result << std::endl;
	}

	return 0;
}