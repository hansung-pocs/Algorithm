#include <iostream>

using namespace std;

int main(){
	int ** data;
	int * item;
	int * weight;
	int n, k;

	cin >> n >> k;
	
	data = new int*[n+1];
	item = new int[n+1];
	weight = new int[n+1];

	for(int i=0;i<n+1;++i){
		data[i] = new int[k+1];
		
		if(i>0)
			cin >> weight[i] >> item[i];
		for(int j=0;j<k+1;++j)
			data[i][j] = 0;
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			if(j>=weight[i]){
				int a = data[i-1][j];
				int b = data[i-1][j-weight[i]]+item[i];
				data[i][j] = (a>b)?a:b;
			}
			else
				data[i][j] = data[i-1][j];
		}
	}
	cout << data[n][k] << " ";
	return 0;
}
