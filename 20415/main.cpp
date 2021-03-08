#include <iostream>
#include <vector>

using namespace std;

int n,s,g,p,d;

int returnMin(char grade)
{
	if(grade >= 'A' && grade <= 'Z') grade+=('a'-'A');
	if(grade == 'b')
	{
		return 0;
	}
	else if(grade == 's')
	{
		return s;
	}
	else if(grade == 'g')
	{
		return g;
	}
	else if(grade == 'p')
	{
		return p;
	}
	else
	{
		return d;
	}

}

int returnMax(char grade)
{
	if(grade >= 'A' && grade <= 'Z') grade+=('a'-'A');
	if(grade == 'b')
	{
		return s-1;
	}
	else if(grade == 's')
	{
		return g-1;
	}
	else if(grade == 'g')
	{
		return p-1;
	}
	else if(grade == 'p')
	{
		return d-1;
	}
	else
	{
		return d*2;
	}

}

int main()
{
	vector<char> grade;
	vector<int> result;
	
	cin >> n >> s >> g >> p >> d;
	getchar();
	for(int i=0;i<n;++i)
	{
		grade.push_back(getchar());
	}
	for(int i=0;i<n;++i)
	{
		if(i==0)
		{
			result.push_back(returnMax(grade[i]));
		}
		else
		{
			int cost = returnMax(grade[i]) - result[i-1];
			if(returnMax(grade[i]) == d*2)
				cost = d;
			if(cost>=0)
				result.push_back(cost);
			else
			{
				result.push_back(0);
				result[i-1] = returnMax(grade[i]);
				for(int j=i-1;j>0;--j)
				{
					if(result[j-1]+result[j] < returnMin(grade[j]))
					{
						result[j-1] = returnMin(grade[j])-result[j];
					}
					else if(result[j-1]+result[j] > returnMax(grade[j]))
					{
						result[j-1] = returnMax(grade[j])-result[j];
					}
					else break;
				}
			}
		}
	}
	int sum = 0;
	for(int i=0;i<n;++i)
		sum += result[i];
	cout << sum;

	return 0;
}
