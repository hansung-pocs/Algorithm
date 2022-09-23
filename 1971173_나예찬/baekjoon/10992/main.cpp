#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;++i)
	{
		if(i == n-1)
		{
			for(int j=0;j<2*n-1;++j)
				cout << "*";
		}
		else
		{
			for(int j=0;j<n-i-1;++j)
				cout << " ";
			cout << "*";
			for(int j=0;j<i*2-1;++j)
				cout << " ";
			if(i!=0) cout << "*";
		}
		cout << endl;
	}
	return 0;
}
