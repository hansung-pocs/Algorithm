#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> data[3];
	vector<int> result[3];

	int n;
	
	cin >> n;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<3;++j)
		{
			int x;
			cin >> x;
			

			data[j].push_back(x);
		}
	}

	int min = -1;

	for(int i=0;i<3;++i)
	{
		for(int j=0;j<n;++j)
		{	
			int conv_arr[3][3]={
				{0,1,2},
				{1,2,0},
				{2,0,1}
			};
			if(j==0)
			{
				result[conv_arr[i][0]].push_back(data[conv_arr[i][0]][0]);
				result[conv_arr[i][1]].push_back(-1);
				result[conv_arr[i][2]].push_back(-1);
			}
			else if(j<n-1)
			{
				for(int k=0;k<3;++k)
				{
					int value1 = result[conv_arr[k][1]][j-1];
					int value2 = result[conv_arr[k][2]][j-1];

					if(value1>=0 && value2>=0 && value1<value2)
					{
						result[conv_arr[k][0]].push_back(value1+data[k][j]);
					}
					else if(value1>=0 && value2>=0 && value1>=value2)
					{
						result[conv_arr[k][0]].push_back(value2+data[k][j]);
					}
					else if(value1<0 && value2>=0)
					{
						result[conv_arr[k][0]].push_back(value2+data[k][j]);
					}
					else if(value1>=0 && value2<0)
					{
						result[conv_arr[k][0]].push_back(value1+data[k][j]);
					}
					else
					{
						result[conv_arr[k][0]].push_back(-1);
					}

				}
			}
			else
			{
				for(int k=0;k<3;++k)
				{
					if(k==i)
					{
						result[conv_arr[k][0]].push_back(-1);
						continue;
					}
					int value1 = result[conv_arr[k][1]][j-1];
					int value2 = result[conv_arr[k][2]][j-1];

					if(value1>=0 && value2>=0 && value1<value2)
					{
						result[conv_arr[k][0]].push_back(value1+data[k][j]);
					}
					else if(value1>=0 && value2>=0 && value1>=value2)
					{
						result[conv_arr[k][0]].push_back(value2+data[k][j]);
					}
					else if(value1<0 && value2>=0)
					{
						result[conv_arr[k][0]].push_back(value2+data[k][j]);
					}
					else if(value1>=0 && value2<0)
					{
						result[conv_arr[k][0]].push_back(value1+data[k][j]);
					}
					else
					{
						result[conv_arr[k][0]].push_back(-1);
					}

				}

			}
		}
		for(int j=0;j<3;++j)
		{
			if(result[j][n-1]>=0 && (result[j][n-1]<min||min==-1))
				min=result[j][n-1];
		}
		for(int j=0;j<3;++j)
		{
			result[j].clear();
		}
	}


	cout << min;

	return 0;
}
