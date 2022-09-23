#include <iostream>
#include <string>

int arr[1000000];
int available[10];

bool isAccessible(int i)
{
	if (i < 0 || i>999999) return false;
	std::string num = std::to_string(i);
	bool result = true;
	for (char & ch : num)
	{
		if (!available[ch - '0'])
		{
			result = false;
			break;
		}
	}
	return result;
}

int getCount(int left, int right, int fail)
{
	int extra = 0;
	while (true)
	{
		int result = -1;
		if (left>=0 && left<1000000 && arr[left] != -1)
			result = arr[left];

		if (right >= 0 && right < 1000000 && arr[right] != -1) {
			if (result == -1) result = arr[right];
			else if (arr[right] < result) result = arr[right];
		}
		if (result != -1)
			return result+extra;
		if ((left < 0 || left >= 1000000) && (right < 0 || right >= 1000000))
			return -1;

		if (extra > fail) return -1;

		else
		{
			int countA = -1, countB = -1;

			if (isAccessible(left))
			{
				arr[left] = std::to_string(left).size()+extra;
				countA = arr[left];
			}

			if (isAccessible(right))
			{
				arr[right] = std::to_string(right).size()+extra;
				countB = arr[right];
			}

			if (countA != -1 && countB != -1)
			{
				return (countA < countB) ? countA : countB;
			}
			else if (countA != -1)
			{
				return countA;
			}

			else if (countB != -1)
			{
				return countB;
			}
		}
		--left; ++right;
		++extra;
	}
}


int main()
{
	int n, m;
	for (int i = 0; i < 1000000; ++i)
		arr[i] = -1;
	for (int i = 0; i < 10; ++i)
		available[i] = true;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		int k;
		scanf("%d", &k);
		available[k] = false;
	}

	int v2 = abs(100 - n);
	int v1 = getCount(n, n, v2);

	if(v1==-1 || v1>v2)
		printf("%d", v2);

	else
		printf("%d", v1);


	return 0;
}