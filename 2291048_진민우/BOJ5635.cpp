#include <iostream>
#include <string>

using namespace std;
bool year(int n);

int main(void) {
    int max_day = 0;
    int min_day = 0;
    int arr1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //평년
    int arr2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //윤년
    int k;
    int j = 0;//위치기억
    int n; //학생수


    cin >> n; //학생수 입력

    string name[n];
    int birth[n][3]; //일 월 년
    int day[n]; //총 일수

    for (int i = 0; i < n; i++) {
        cin >> name[i] >> birth[i][0] >> birth[i][1] >> birth[i][2];
    }

    /*day[i] 전부 0으로 초기화*/
    for (int i = 0; i < n; i++) {
        day[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        day[i] += birth[i][0]; //일
        switch (birth[i][1]) {
            case 1:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 2:
                if(year(birth[i][2]) == true) { //윤년
                    for(int k = 1; k <= birth[i][1]; k++){
                        day[i] += arr2[k]; //윤년일 때, arr2배열 이용
                    }
                    break;
                }
                else { //평년
                    for(int k = 1; k <= birth[i][1]; k++){
                        day[i] += arr1[k];
                    }
                    break;
                }
            case 3:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 4:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 5:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 6:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 7:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 8:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 9:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 10:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 11:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
            case 12:
                for(int k = 1; k <= birth[i][1]; k++){
                    day[i] += arr1[k];
                }
                break;
        }
        day[i] += birth[i][2] * 365;
    }

    max_day = day[0]; //day가 크면 나이 어림
    for (k = 0; k < n; k++) {
        if (max_day < day[k]) {
            max_day = day[k];
            j = k; //총 일수가 큰 위치 k를 j에 저장
        }
    }
    cout << name[j] << endl;

    min_day = day[0]; //day가 작으면 나이 많음
    for (k = 0; k < n; k++) {
        if (min_day > day[k]) {
            min_day = day[k];
            j = k; //총 일수가 작은 위치 k를 j에 저장
        }
    }
    cout << name[j] << endl;
}

bool year(int year)
{
    if((year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0) //윤년
        return true;
    else //평년
        return false;
}