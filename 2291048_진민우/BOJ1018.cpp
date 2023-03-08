#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int N; //행
    int M; //열

    cin >> N >> M;
    string board[N];

    for (int i = 0; i < N; i++) {
        cin >> board[i]; //체스보드 입력
    }

    int a = 0;
    int b = 0;
    int min = 65;
    int start_B = 0;
    int start_W = 0;

    for (int i = 0; i < N - 7; i++) {
        for (int j = 0; j < M - 7; j++) {
            start_B = 0; //처음에 B가 칠해져 있다고 가정했을 때, 다시 칠해야 하는 정사각형의 개수
            start_W = 0; //처음에 W가 칠해져 있다고 가정했을 때, 다시 칠해야 하는 정사각형의 개수
            a = 0;
            b = 0;

            //처음에 B가 칠해져 있다고 가정
            for (int n = i; n < i + 8; n++) {
                for (int m = j; m < j + 8; m++) {

                    a = n - i;
                    b = m - j;

                    if ((a + b) % 2 == 0) {
                        if (board[n][m] != 'B')
                            start_B++;
                    } else {
                        if (board[n][m] != 'W')
                            start_B++;
                    }
                }
            }
            if (min > start_B)
                min = start_B;

            //처음에 W가 칠해져 있다고 가정
            for (int n = i; n < i + 8; n++) {
                for (int m = j; m < j + 8; m++) {

                    a = n - i;
                    b = m - j;

                    if ((a + b) % 2 == 0) {
                        if (board[n][m] != 'W')
                            start_W++;
                    } else {
                        if (board[n][m] != 'B')
                            start_W++;
                    }
                }
            }

            if (min > start_W)
                min = start_W;

            /*B가 첫번째로 올 때, W가 첫번째로 올 때 -> 둘 중에서 더 적게 칠해는 것을 구하면됨*/
        }
    }
    cout << min << endl;
}