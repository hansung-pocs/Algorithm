#include <iostream>

int main()
{
	int a = 0, b = 1;
	long long i = 0;
	do{
		++i;
		b = a + b;
		a = b - a;
		a %= 1000000;
		b %= 1000000;
	} while (!(a == 0 && b == 1));

	int * k = new int[i];
	a = 0;
	b = 1;
	for (long long j = 0; j < i; ++j)
	{
		k[j] = a;
		b = a + b;
		a = b - a;
		a %= 1000000;
		b %= 1000000;
	}

	long long num;
	scanf("%lld", &num);
	num %=i;
	printf("%d", k[num]);


	return 0;
}