#include <iostream>
#include <algorithm>

int sumN(int n)
{
	if (n < 0) return 0;
	return n * (n + 1) / 2;
}

void printCount(int a, int b, int n)
{
	int result = sumN(b-a-2) - sumN(n - a - 2) - sumN(b - n - 2);
	printf("%d", result);
}

int main() {
	int n;
	scanf("%d", &n);
	int * arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",arr+i);
	}
	std::sort(arr, arr + n);
	int k;
	scanf("%d", &k);
	for (int i = -1; i < n - 1; ++i)
	{
		if (i == -1 && k <= arr[i + 1])
		{
			printCount(0, arr[i + 1], k);
			break;
		}
		else if (arr[i] <= k && k <= arr[i + 1])
		{
			printCount(arr[i], arr[i + 1], k);
			break;
		}
	}
	delete[] arr;
	return 0;
}