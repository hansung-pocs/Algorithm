#include <iostream>

int main()
{
	int nn, min=-1, max=-1;
	scanf("%d", &nn);
	for (int i = 0; i < nn; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (min == -1 || min > tmp)
			min = tmp;
		if (max == -1 || max < tmp)
			max = tmp;
	}
	printf("%d", min * max);

	return 0;
}