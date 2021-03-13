#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(vector<int> data, vector<int> output, int n)
{
	int dataLen = data.size();
	if(n==0)
	{
		for(int & itr : output)
			printf("%d ",itr);
		printf("\n");
		return;
	}
	for(int i=0;i<dataLen;++i)
	{
		vector<int> newOutput;
		newOutput.assign(output.begin(), output.end());
		newOutput.push_back(data[i]);
		vector<int> newVector;
		for(int j=0;j<i;++j)
			newVector.push_back(data[j]);
		for(int j=i+1;j<dataLen;++j)
			newVector.push_back(data[j]);
		permutation(newVector, newOutput, n-1);
	}
}

int main()
{
	int m, n;
	vector<int> vInt;
	scanf("%d %d",&m,&n);

	for(int i=0;i<m;++i)
	{
		int x;
		scanf("%d",&x);
		vInt.push_back(x);
	}
	sort(vInt.begin(), vInt.end());

	vector<int> output;
	permutation(vInt, output, n);

	return 0;
}
