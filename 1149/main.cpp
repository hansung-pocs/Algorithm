#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count;
	cin >> count;
	int **data = new int*[count];
	int **sum = new int*[count];
	for (int i = 0; i < count; i++)
	{
		data[i] = new int[3];
		sum[i] = new int[3];
	}
	for (int i = 0; i < count; i++)
	{
		cin >> data[i][0] >> data[i][1] >> data[i][2];
		if (i == 0)
		{
			sum[0][0] = data[0][0];
			sum[0][1] = data[0][1];
			sum[0][2] = data[0][2];
		}
		else
		{
			int a = sum[i- 1][0], b = sum[i - 1][1], c = sum[i - 1][2];
			sum[i][0] = data[i][0] + ((b < c) ? b : c);
			sum[i][1] = data[i][1] + ((a < c) ? a : c);
			sum[i][2] = data[i][2] + ((a < b) ? a : b);
		}
	}
	int min = (sum[count - 1][0] < sum[count - 1][1]) ? sum[count - 1][0] : sum[count - 1][1];
	min = (min< sum[count - 1][2]) ? min: sum[count - 1][2];
	cout << min << endl;

	return 0;
}