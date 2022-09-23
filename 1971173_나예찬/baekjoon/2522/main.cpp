#include <iostream>

using namespace std;

int main()
{
	int n;
	int pos = 1;
	cin >> n;
	for(int i=1;i>=1;i+=pos)
	{
		if(i>=n) pos=-1;
		for(int j=0;j<n-i;++j)
			cout << ' ';
		for(int j=0;j<i;++j)
			cout << '*';
		cout << endl;
	}
	return 0;
}
