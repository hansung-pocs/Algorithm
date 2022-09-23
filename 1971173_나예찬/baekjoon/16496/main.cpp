#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ncmp(int a, int b)
{
	string strA, strB;
	strA = to_string(a);
	strB = to_string(b);
	unsigned long long resultA = stoull(strA+strB);
	unsigned long long resultB = stoull(strB+strA);
	return resultA>resultB;
}

int main()
{
	int n;
	vector<int> nums;
	cin>>n;

	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		nums.push_back(x);
	}
	
	sort(nums.begin(), nums.end(), ncmp);

	bool nonZeroOccured = false;
	int nLen = nums.size();

	for(int i=0;i<nLen; ++i)
	{
		if(nums[i] == 0)
		{
			if(nonZeroOccured || i == nLen-1)
			{
				cout << nums[i];
			}
		}
		else
		{
			cout << nums[i];
			nonZeroOccured = true;
		}
	}

	return 0;
}
