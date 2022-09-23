#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strA, strB;
	cin >> strA >> strB;

	int lenA, lenB;
	lenA = strA.size();
	lenB = strB.size();

	int ** data = new int*[lenA];
	for(int i=0;i<lenA;++i)
		data[i] = new int[lenB];
	
	for(int i=0;i<lenA;++i)
	{
		for(int j=0;j<lenB;++j)
		{
			if(i==0 && j==0)
			{
				data[i][j] = (strA[i]==strB[j]);
			}
			else if(i==0)
			{
				if(strA[i]==strB[j])
				{
					data[i][j] = 1;
				}
				else
				{
					data[i][j] = data[i][j-1];
				}
			}
			else if(j==0)
			{
				if(strA[i]==strB[j])
				{
					data[i][j] = 1;
				}
				else
				{
					data[i][j] = data[i-1][j];
				}
			}
			else
			{
				if(strA[i]==strB[j])
				{
					data[i][j] = data[i-1][j-1] + 1;
				}
				else
				{
					data[i][j] = (data[i-1][j] > data[i][j-1]) ? data[i-1][j] : data[i][j-1];
				}
			}
		}
	}
	
	cout << data[lenA-1][lenB-1];

	return 0;
}
