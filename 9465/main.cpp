#include <iostream>
#include <vector>

int *arr1, *arr2, *sum1, *sum2;

int max_sum(int n, int m)
{
	if (n == 0) return m ? arr2[0] : arr1[0];
	else if (n==1) return m ? arr1[0]+ arr2[1] : arr2[0]+ arr1[1];
	else
	{
		int v1 = m ? sum1[n - 1] : sum2[n - 1];
		int v2 = m ? sum1[n - 2] : sum2[n - 2];
		return (v1 > v2 ? v1 : v2) + (m ? arr2[n] : arr1[n]);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int n;
		scanf("%d", &n);
		arr1 = new int[n];
		arr2 = new int[n];

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", arr1+i);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", arr2 + i);
		}

		sum1 = new int[n];
		sum2 = new int[n];

		for (int i = 0; i < n; ++i)
		{
			sum1[i] = max_sum(i, 0);
			sum2[i] = max_sum(i, 1);
		}

		printf("%d\n", (sum1[n - 1] > sum2[n - 1]) ? sum1[n - 1] : sum2[n - 1]);

	}
	return 0;
}