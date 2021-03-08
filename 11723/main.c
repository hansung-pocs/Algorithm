#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	int k;
	int arr[21] = { 0 ,};
	char str[7];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", &str);
		if (!strcmp(str, "add"))
		{
			scanf("%d", &k);
			arr[k] = 1;
		}
		else if (!strcmp(str, "remove"))
		{
			scanf("%d", &k);
			arr[k] = 0;
		}
		else if (!strcmp(str, "check"))
		{
			scanf("%d", &k);
			printf("%d\n", arr[k]);
		}
		else if (!strcmp(str, "toggle"))
		{
			scanf("%d", &k);
			arr[k] = !arr[k];
		}
		else if (!strcmp(str, "all"))
		{
			for (int i = 0; i <= 20; ++i)
				arr[i] = 1;
		}
		else if (!strcmp(str, "empty"))
		{
			for (int i = 0; i <= 20; ++i)
				arr[i] = 0;
		}
	}
}