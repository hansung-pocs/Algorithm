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

int ncmp2(int a, int b)
{
	string strA, strB;
	strA = to_string(a);
	strB = to_string(b);
	if(strA.length() != strB.length()) 
		return strA.length()>strB.length();
	else 
		return a>b;
}

int main()
{
	int k,n;
	vector<int> nums;
	cin>>k>>n;

	for(int i=0;i<k;++i)
	{
		int x;
		cin>>x;
		nums.push_back(x);
	}

	sort(nums.begin(), nums.end(), ncmp2);

	for(int i=0;i<n-k;++i)
		nums.push_back(nums[0]);
	
	sort(nums.begin(), nums.end(), ncmp);

	for(int &i:nums)
	{
		cout << i;
	}

	return 0;
}
