#include <iostream>

int main()
{
	int n,r,result=1,res2=1;
	scanf("%d%d", &n,&r);
	for (int i = n - r + 1; i <= n; ++i)
	{
		result *= i;
	}
	for (int i = 1; i <= r; ++i)
	{
		res2 *= i;
	}
	printf("%d", result / res2);
	return 0;
}