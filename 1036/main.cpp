#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int orderIndex[36];

int charToDec(char ch)
{
	if(ch >= '0' && ch <= '9')
		return ch-'0';
	if(ch >= 'A' && ch <= 'Z')
		return ch-'A'+10;
}

char decToChar(int x)
{
	if(x>=0 && x<=9)
		x+='0';
	if(x>=10 && x<=35)
		x+=('A'-10);
	return (char)x;
}

void processCarry(array<int,52> * data)
{
	for(int i=0;i<51;++i)
	{
		(*data)[i+1] += ((*data)[i]/36);
		(*data)[i] %= 36;
	}
}

bool compareArray(array<int,52> * a, array<int,52> * b)
{
	for(int i=51;i>=1;--i)
	{
		if((*a)[i] != (*b)[i])
		{
			return (*a)[i] > (*b)[i];
		}
	}
	return (*a)[0] > (*b)[0];
}

int main()
{
	array<array<int,52> *,36> carryData;
	array<int,52> sumData = {0};
	
	for(int i=0;i<36;++i)
	{
		carryData[i] = new array<int,52>();
	}

	int n;
	cin >> n;
	
	for(int i=0;i<n;++i)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		
		int lenStr = str.size();
		for(int j=0;j<lenStr;++j)
		{
			int v = charToDec(str[j]);
			(*carryData[v])[j] += (35-v);
			sumData[j] += v;
		}
	}
	for(int i=0;i<36;++i)
		processCarry(carryData[i]);
	processCarry(&sumData);
	
	sort(carryData.begin(), carryData.end(), compareArray);

	int k;
	cin >> k;

	for(int i=0;i<k;++i)
	{
		for(int j=0;j<52;++j)
		{
			sumData[j] += (*(carryData[i]))[j];
		}
	}
	processCarry(&sumData);

	bool nonZeroOccured = false;

	for(int i=51;i>=0;--i)
	{
		if(sumData[i]==0)
		{
			if(nonZeroOccured || i==0)
			{
				cout << decToChar(sumData[i]);
			}
		}
		else
		{
			cout << decToChar(sumData[i]);
			nonZeroOccured = true;
		}
	}
}
