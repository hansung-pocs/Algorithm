#include <iostream>
#include <list>

int main()
{
	int m,n;
	std::cin >> m>>n;
	std::list<int> prime;
	for (int i = 2; i <= n; i++)
	{
		bool isprime = true;
		for (int j : prime)
		{
			if (j*j > i) break;
			if (!(i%j)) {
				isprime = false;
				break;
			}
		}
		if (isprime)
		{
			prime.push_back(i);
			if(i>=m) std::cout << i << "\n";
		}
	}
}