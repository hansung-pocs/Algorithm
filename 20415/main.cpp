#include <iostream>
#include <vector>

using namespace std;

int returnMin(char grade, int s, int g, int p, int d)
{
	cout << grade << endl;
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

int returnMax(char grade, int s, int g, int p, int d)
{
	cout << grade << endl;
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
	int n, s, g, p, d;
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
			result.push_back(returnMax(grade[i],s,g,p,d));
		}
		else
		{
			int cost = returnMax(grade[i],s,g,p,d) - result[i-1];
			if(cost<0)
			{
				result[i-1]+=cost;
				cost = 0;
				for(int j=i-1;j>0;--j)
				{
					
				}
			}
		}
	}

	return 0;
}
