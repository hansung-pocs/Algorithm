#include <iostream>

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int ** input_data, ** result;
int m, n;

using namespace std;

int Recursion(int y, int x);
int main() {
	cin >> m >> n;
	input_data = new int*[m];
	result = new int*[m];

	for (int i = 0; i < m; i++) {
		input_data[i] = new int[n];
		result[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> input_data[i][j];
			result[i][j] = -1;
		}
	}
	cout << Recursion(m - 1, n - 1) << endl;
	return 0;
}

int Recursion(int y, int x) {
	if (y == 0 && x == 0) {
		return 1;
	}

	if (result[y][x] == -1) {
		result[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (input_data[y][x] < input_data[ny][nx]) {
					result[y][x] += Recursion(ny, nx);
				}
			}
		}
	}
	return result[y][x];
}