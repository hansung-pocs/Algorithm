#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using ULL = unsigned long long;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<ULL> v;

	for (int i = 0; i < n; ++i)
	{
		ULL no;
		scanf("%llu", &no);
		v.push_back(no);
	}
	std::make_heap(v.begin(), v.end(), std::greater<ULL>());
	for (int i = 0; i < m; ++i)
	{
		std::pop_heap(v.begin(), v.end(), std::greater<ULL>());
		ULL a = v.back();
		v.pop_back();

		std::pop_heap(v.begin(), v.end(), std::greater<ULL>());
		ULL b = v.back();
		v.pop_back();

		ULL result = a + b;

		v.push_back(result);
		std::push_heap(v.begin(), v.end(), std::greater<ULL>());

		v.push_back(result);
		std::push_heap(v.begin(), v.end(), std::greater<ULL>());
	}
	ULL sum = 0;
	for (ULL & i : v)
		sum += i;

	printf("%llu\n", sum);

	return 0;
}