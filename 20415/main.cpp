#include <iostream>
#include <vector>

using namespace std;

class ResultData{
	int sum;
	int cost;
public:
	ResultData(int sum, int cost)
	{
		this->sum = sum;
		this->cost = cost;
	}
	int getSum(){return sum;}
	int getCost(){return cost;}
};

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
		return d;
	}

}

int main()
{
	int n, s, g, p, d;
	vector<char> grade;
	cin >> n >> s >> g >> p >> d;
	getchar();
	for(int i=0;i<n;++i)
	{
		grade.push_back(getchar());
	}

	vector<ResultData *> * result = new vector<ResultData *>[n];
	for(int i=0;i<n;++i)
	{
		if(i==0)
		{
			int minCost = returnMin(grade[0],s,g,p,d);
			int maxCost = returnMax(grade[0],s,g,p,d);
			cout << minCost << " " << maxCost << endl;
			for(int j=minCost;j<=maxCost;++j)
			{
				result[i].push_back(new ResultData(j,j));
			}
		}
		else
		{
			int baseMinCost = returnMin(grade[i],s,g,p,d);
			int baseMaxCost = returnMax(grade[i],s,g,p,d);
			
			for(ResultData * itr : result[i-1])
			{
				int minCost = (itr->getCost()>baseMinCost)?itr->getCost():baseMinCost;
				cout << minCost << " " << baseMaxCost << endl;
				for(int j=minCost;j<=baseMaxCost;++j)
				{
					result[i].push_back(new ResultData(itr->getSum()+j,j));
				}
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		cout << "---" << i << "---" << endl;
		for(ResultData * itr : result[i])
		{
			cout << itr->getSum() << " " << itr->getCost() << endl;
		}
	}


	return 0;
}
