#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * getPrimeList(int n)
{
	int * arr = (int *)malloc(sizeof(int)*(n+1));
	for (int i = 2; i <= n; ++i)
	{
		arr[i] = i;
	}
	for (int i = 2; i*i <= n; ++i)
	{
		if (!arr[i]) continue;
		for (int j = i<<1; j <= n; j+=i)
		{
			arr[j] = 0;
		}
	}
	int count = 0;

	for (int i = 2; i <= n; ++i)
	{
		if (arr[i]) ++count;
	}
	int * result = (int *)malloc(sizeof(int)*(count+1));

	result[0] = count;
	int index = 1;

	for (int i = 2; i <= n; ++i)
	{
		if (arr[i])
			result[index++] = arr[i];
	}

	free(arr);
	return result;
}

int getNonSquareNumCount(long long min, long long max, int * prime)
{
	int datacount = max - min + 1;
	long long * arr = (long long *)malloc(sizeof(long long)*datacount);
	for (int i = 0; i<datacount; ++i)
	{
		arr[i] = i+min;
	} 
	for (int i = 0; i < *prime; ++i)
	{
		long long j = 0;
		long long pr = (long long)prime[i + 1] * (long long)prime[i + 1];
		long long div = min % pr;
		if (div) j += (pr - div);
		for (; j < datacount; j += pr)
		{
			arr[j] = 0;
		}
	}
	int count = 0;
	for (int i = 0; i < datacount; ++i)
	{
		if (arr[i]) 
			++count;
	}
	return count;
}

int main()
{
	long long min, max;
	scanf("%lld %lld", &min, &max);
	int * res = getPrimeList((int)floorl(sqrtl((long double)max)));
	printf("%d", getNonSquareNumCount(min, max, res));
	return 0;

}