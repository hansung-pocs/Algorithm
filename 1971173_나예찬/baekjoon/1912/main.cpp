#include <iostream>
using namespace std;
int main()
{
	int n, max;
	cin >> n;
	int * arr = new int[n], * arr2 = new int[n];
	int* itr, * itr2;
	
	for (itr = arr; itr < arr + n; itr++)
	{
		cin >> *itr;
	}
	arr2[0] = arr[0];
	for (itr = arr+1, itr2 = arr2+1; itr < arr + n; itr++, itr2++)
	{
		if (*(itr2 - 1) + *itr > * itr)* itr2 = *(itr2 - 1) + *itr;
		else *itr2 = *itr;
	}
	max = arr2[0];
	for (itr = arr2+1; itr < arr2 + n; itr++)
	{
		if (max < *itr) max = *itr;
	}
	cout << max << endl;
	return 0;
}