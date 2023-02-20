#include <iostream>

using namespace std;

//구조체 정의
typedef struct bridge {
    int N;
    int M;
    unsigned long long result = 0;
} Bridge;

//팩토리얼 구하는 함수
unsigned long long factorial(int n) {
    int num = n;
    unsigned long long result = 1;
    while (num >= 1) {
        result = result * num;
        num--;
    }
    return result;
}

//특정한 수를 특정한 횟수 만큼 1씩 빼면서 곱하는 함수.
unsigned long long half_factorial(int m, int n)
{
    int num = m;
    unsigned long long result = 1;
    for(int i = 0; i < n; i++){
        result = result * num;
        num--;
    }
    return result;
}


int main(void) {
    int T;
    cin >> T; //테스트 케이스 입력

    Bridge bridge[T]; //테이스 케이스 만큼 구조체 생성

    for (int i = 0; i < T; i++) {
        cin >> bridge[i].N >> bridge[i].M; //N과 M입력
        if(bridge[i].N > (bridge[i].M / 2)){ // 조합의 특성 => mCn = mCm-n 이렇게 안하면 오버플로우 남
            bridge[i].N = bridge[i].M - bridge[i].N;
        }
        bridge[i].result = half_factorial(bridge[i].M, bridge[i].N) / factorial(bridge[i].N); //조합을 구함 = mCn
        cout << bridge[i].result << "\n";
    }
}
