#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int a = -1, b = -1;
	int arr[] = { 3,6,9,12 };
	for (int i = 0; i < 4; i++) {
		if (arr[i] > N)continue;
		int res = N - arr[i];
		if (res % 5 == 0) {
			a = arr[i] / 3;
			b = res / 5;
			break;
		}
		else {
			continue;
		}
	}
	if (a != -1)cout << a + b;
	else if (N % 5 == 0)cout << N / 5;
	else {
		cout << -1;
	}
}