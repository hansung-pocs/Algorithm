#include <iostream>

using namespace std;

int main(void) {
    int k = 0;
    int sigma = 0;
    int sum = 0; //분모 + 분자
    int i = 0; //분모
    int n;
    cin >> n;

    /*몇 행에 있는지*/
    while (true) {
        if (k * (k + 1) / 2 < n && n <= (k + 1) * (k + 2) / 2) {
            k = k + 1;
            break;
        } else {
            k++;
        }
    }
    sigma = k * (k + 1) / 2;
    sum = k + 1;

    if (k % 2 == 0) { //짝수 행, i = 1
        i = 1;
        for(int j = 0; j < (sigma - n); j++){
            i++;
        }
        cout << sum - i << "/" << i << endl;
    } else { //홀수 행, i = k
        i = k;
        for(int j = 0; j < (sigma - n); j++){
            i--;
        }
        cout << sum - i << "/" << i << endl;
    }

    return 0;
}