#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare_length(string words1, string words2)
{
    if(words1.length() != words2.length())
        return words1.length() < words2.length();
    else
        return words1 < words2;
}


int main(void)
{
    int N;
    cin >> N;
    string words[N];

    for(int i = 0; i < N; i++){
        cin >> words[i];
    }

    sort(words, words + N, compare_length); //길이 순 정렬

    for(int i = 0; i < N; i++){
        if(i < N - 1){
            if(words[i].compare(words[i + 1]) == 0) //쭉 출력하다가 다음 것과 같으면 생략
                continue;
        }
        cout << words[i] << endl;
    }
}