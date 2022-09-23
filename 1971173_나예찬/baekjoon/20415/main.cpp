#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,s,g,p,d;

int returnMin(char grade)
{
	if(grade == 'B')
	{
		return 0;
	}
	else if(grade == 'S')
	{
		return s;
	}
	else if(grade == 'G')
	{
		return g;
	}
	else if(grade == 'P')
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
	if(grade == 'B')
	{
		return s-1;
	}
	else if(grade == 'S')
	{
		return g-1;
	}
	else if(grade == 'G')
	{
		return p-1;
	}
	else if(grade == 'P')
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
	vector<int> result;
	string grade;

	cin >> n >> s >> g >> p >> d;
	cin >> grade;
	for(int i=0;i<n;++i)
	{
		if(i==0)
		{
			int cost;

			if(grade[i] == 'D')
				cost = d;
			else
				cost = returnMax(grade[i]);

			result.push_back(cost);
		}
		else
		{
			int cost;

			if(grade[i] == 'D')
				cost = d;

			else if(result[i-1] <= returnMax(grade[i]))
				cost = returnMax(grade[i]) - result[i-1];
			else
			{
				cost = 0;
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
			result.push_back(cost);
		}
	}
	int sum = 0;
	for(int & i : result)
	{
		sum+=i;
	}
	cout << sum;

	return 0;
}
