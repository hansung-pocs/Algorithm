#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[10] = {1,1,1,1,1,1,1,1,1,1};
	for(int i=0;i<n-1;++i){
		for(int j=0;j<10;++j)
		{
			int tmp;
			if(j==0)
			{
				tmp = arr[j];
				for(int k=1;k<10;++k)
				{
					arr[j]+=arr[k];
				}
			}
			else
			{
				int tmp2 = arr[j];
				arr[j] = arr[j-1] - tmp;
				tmp = tmp2;
			}
		}
		for(int j=0;j<10;++j)
		{
			if(arr[j] >= 10007)
				arr[j] %= 10007;
		}
	}
	int sum = 0;
	for(int i=0;i<10;++i) sum+=arr[i];
	cout << sum%10007;
	return 0;
}
