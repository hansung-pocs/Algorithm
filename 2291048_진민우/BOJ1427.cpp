#include <iostream>
using namespace std;

int main(void) {
    int i = 0;
    int j = 0;
    int least;
    int temp;
    int arr[10]; //10자리수가 들어갈 것임
    int N;
    cin >> N;
    int index = 0;

    while (N != 0) {
        arr[index] = N % 10;
        N = N / 10;
        index++;
    }

    for (i = 0; i < index - 1; i++){
        least = i;
        for(j = i + 1; j < index; j++){
            if(arr[least] > arr[j]){
                least = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[least];
        arr[least] = temp;
    }

    for(i = index - 1; i >= 0; i--){
        cout << arr[i];
    }
}