#include <iostream>
using namespace std;

bool arithProgression(int arr[], int k) {
    int diff = 0;
    if(k == 4) //4자리수일 때 -> 1000일 경우밖에 없으므로 한수X
        return false;
    else if(k == 3) { //3자리수일 때
        diff = arr[0] - arr[1]; //공차를 구함
        if(arr[1] - arr[2] == diff) //다음 비교시 공차가 일치하면 -> 한수O
            return true;
        else //일치 안하면 -> 한수X
            return false;
    }
    else if(k == 2) //2자리수일 때 -> 무조건 한수
        return true;
    else if(k == 1) //1자리수일 때 -> 무조건 한수
        return true;
}

int main(void) {
    int count = 0;
    int arr[4];
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){

        //0으로 다 초기화
        for(int j = 0; j < 4; j++){
            arr[j] = 0;
        }

        //배열에 각 자리의 수 저장,  123이면 -> [3][2][1] 이렇게
        int store = i;
        int k = 0;
        while(store != 0){
            arr[k] = store % 10;
            store = store / 10;
            k++; //몇자리 수 인지, 만약 123이면 -> 3자리수
        }

        if(arithProgression(arr, k) == true) //'배열'과 '자릿수'를 인자로
            count++; //'한수'면 count 증가
    }
    cout << count;
}