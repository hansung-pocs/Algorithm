#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main()
{
	int T;
	std::cin >> T;
	std::cin.ignore();
	for (int i = 1; i <= T; ++i)
	{
		std::stack<std::string> data;
		std::string sentence;
		std::getline(std::cin, sentence);

		std::stringstream sstr;
		sstr.str(sentence);
		std::string word;
		while (sstr >> word)
		{
			data.push(word);
		}
		std::cout << "Case #" << i << ": ";
		while (!data.empty())
		{
			std::cout << data.top() << " ";
			data.pop();
		}
		std::cout << std::endl;
	}
}