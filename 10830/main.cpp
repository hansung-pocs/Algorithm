#include <iostream>
#include <unordered_map>

using namespace std;

void multiflyMatrix(int dest[5][5], int ma[5][5], int mb[5][5], int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			dest[i][j] = 0;
			for(int k=0;k<n;++k){
				dest[i][j] += ma[i][k]*mb[k][j];
			}
		}
	}
}

void squareMatrix(int matrix[5][5], int n)
{
	int matrix2[5][5];
	multiflyMatrix(matrix2, matrix, matrix, n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			matrix[i][j] = matrix2[i][j];
			matrix[i][j] %= 1000;
		}
	}
}

int main()
{
	int n;
	long long b;
	int matrix[5][5];
	int result[5][5];
	int tmpArr[5][5];
	cin >> n >> b;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cin >> matrix[i][j];
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			result[i][j] = (i==j);
		}
	}
	int i=0;
	while(b>0)
	{
		if(b%2)
		{
			multiflyMatrix(tmpArr, result, matrix, n);
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<n;++j)
				{
					result[i][j]=tmpArr[i][j];
					result[i][j] %= 1000;
				}
			}
		}

		b/=2;
		if(b>0) squareMatrix(matrix, n);
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}
