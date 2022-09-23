#include <stdio.h>
#include <math.h>

int sqcount(int n, int * arr)
{
	if (n == 0) return 0;
	int max = (int)floor(sqrtf(n));
	int min = (int)floor(sqrtf(n / 2));
	int min_count = 4;
	for (int i = max; i >= min; --i)
	{
		int left_over = n - (i*i);
		if (left_over != 0) {
			if(min_count > arr[left_over]) 
				min_count = arr[left_over];
		}
		else {
			min_count = 0;
			break;
		}
	}
	arr[n] = min_count;
	return min_count+1;
}

int main()
{
	int * arr;
	int n;
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*(n+1));

	for (int i = 0; i <= n; ++i)
	{
		arr[i] = sqcount(i, arr);
	}
	printf("%d", arr[n]);
	return 0;
}