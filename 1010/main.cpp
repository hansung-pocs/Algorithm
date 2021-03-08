#include <iostream>

int main()
{
	int c[31][31];
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {

			if (i == j || j == 0)
				c[i][j] = 1;
			else
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", c[b][a]);
	}

	return 0;
}