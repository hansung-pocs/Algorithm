#include <iostream>
#include <stack>

int main()
{
	char x;
	int count = 0;
	int sum = 0;
	char last_char = '\0';
	while ((x = std::cin.get())!='\n')
	{
		if (last_char!='\0' && last_char == '(' && x == ')')
		{
			--count;
			sum += count;
		}
		else
		{
			if (x == '(')
				++count;
			else if (x == ')')
			{
				--count;
				++sum;
			}
		}
		last_char = x;
	}
	std::cout << sum << std::endl;
	return 0;
}