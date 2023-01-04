#include <iostream>
using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int data;
	cin >> data;
	if (90 <= data && data <= 100)
	{
		cout << 'A';
	}
	else if (80 <= data && data <= 89) {
		cout << 'B';
	}
	else if (70 <= data && data <= 79)
	{
		cout << 'C';
	}
	else if (60 <= data && data <= 69)
	{
		cout << 'D';
	}
	else {
		cout << 'F';
	}
}