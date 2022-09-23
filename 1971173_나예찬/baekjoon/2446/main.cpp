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
		for(int j=0;j<i-1;++j)
			cout << ' ';
		for(int j=0;j<2*(n-i)+1;++j)
			cout << '*';
		cout << endl;
	}
	return 0;
}
