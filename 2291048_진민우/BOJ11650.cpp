#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Pos { //구조체 정의
    int x;
    int y;
} Pos;

bool comp(Pos pos1, Pos pos2) {
    if(pos1.x != pos2.x){ //x좌표 같지 않다면
        return pos1.x < pos2.x; //오름차순
    }
    else{ //x좌표 같다면
        return pos1.y < pos2.y; //그때는 y좌표 오름차순
    }
}

int main(void) {
    int N;
    cin >> N;

    Pos pos[N]; //N개의 구조체 배열 선언

    for (int i = 0; i < N; i++) {
        cin >> pos[i].x >> pos[i].y;
    }

    sort(&pos[0], &pos[0] + N, comp);

    for(int i = 0; i < N; i++){
        cout << pos[i].x << " " << pos[i].y << "\n";
    }
}