#include <iostream>

using namespace std;

int dataArr[9];

void f(int n, int m, int k)
{
	if(k>m)
	{
		for(int i=1;i<=m;++i)
			cout << dataArr[i] << " ";
		cout << endl;
		return;
	}
	int start = 1;
	if(k>1) start = dataArr[k-1];
	for(int i=start;i<=n;++i)
	{
		dataArr[k] = i;
		f(n, m, k+1);
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	f(n,m,1);
	return 0;
}
