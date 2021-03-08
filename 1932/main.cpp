#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ** arr = new int*[n];
	int ** sum = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		sum[i] = new int[n];
		for (int j = 0; j < n; j++) arr[i][j] = -1;
		for (int j = 0; j < n; j++) sum[i][j] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == 0) sum[0][0] = arr[0][0];
			else if (j == 0)
			{
				sum[i][0] = sum[i - 1][0] + arr[i][0];
			}
			else if (j == i)
			{
				sum[i][i] = sum[i - 1][j-1] + arr[i][i];
			}
			else
			{
				int a = sum[i - 1][j - 1];
				int b = sum[i - 1][j];
				sum[i][j] = ((a > b) ? a : b) + arr[i][j];
			}
		}
	}
	int max = sum[n - 1][0];

	for (int i = 1; i < n; i++)
	{
		if (max < sum[n - 1][i]) max = sum[n - 1][i];
	}

	cout << max << endl;


	return 0;
}