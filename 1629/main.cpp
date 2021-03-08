#include <iostream>

using namespace std;

int func(int a, int b, int c)
{
	if(b==1) return a % c;
	long long x = func(a, b/2, c);
	x*=x;
	x%=c;
	if(b%2){
		x*=a;
		x%=c;
	}
	return x;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << func(a,b,c);
	return 0;
}
