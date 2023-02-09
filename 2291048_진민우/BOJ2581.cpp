#include <iostream>

using namespace std;

int check_primeNum(int n);

int main(void) {
    int M; //min
    int N; //max
    int sum = 0; //합
    int min = -1;
    int k = 0;

    cin >> M;
    cin >> N;

    for (int i = M; i <= N; i++) {
        if (check_primeNum(i) == 1) {
            if (k == 0) { // 처음 한번만 실행
                min = i; //가장 작은 소수
                k = 1;
            }
            sum = sum + i;
        }
    }

    if (sum == 0) { // 소수가 없으면
        cout << min << endl;
    } else {
        cout << sum << endl;
        cout << min << endl;
    }
}

int check_primeNum(int n) {
    if(n == 1) //1은 소수가 아님
        return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0; //소수 아님
    }
    return 1; //소수임
}