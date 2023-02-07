#include <stdio.h>
#include <string.h>

int CheckGroupWord(char word[][100], int N);

int main(void)
{
    int N;
    int count = 0;
    scanf("%d", &N);

    char word[N][100]; //문자열 배열 (2차원 배열에 담음)
    for(int i = 0; i < N; i++){
        scanf("%s%*c", &word[i]); //단어 입력 받음
    }

    for(int i = 0; i < N; i++){
        if(CheckGroupWord(word, i) == 1)
            count++;
    }
    printf("%d\n", count);
    return 0;
}

int CheckGroupWord(char word[][100], int N)
{
    int size = strlen(word[N]); //단어의 길이
    int arr[26] = {0};
    int alpha = 0; //알파벳 종류 수
    int not_zero_count; //
    int i = 0;
    int j = 0;
    int index = 0;

    //알파벳 종류 수
    for(i = 0; i < size; i++){
        arr[word[N][i] - 97]++; //arr배열은 26개 공간이있음
                                //만약 a라면 arr[0]++해주고, c라면 arr[2]++을 해줌
    }
    for(i = 0; i < 26; i++){
        if(arr[i] != 0) //arr배열의 요소가 0이 아니면 한번이상 등장했다는 뜻
            alpha++; //알파벳 종류 수
    }

    //배열 초기화(arr배열 재사용 하려고 전부 0으로 초기화)
    for(i = 0; i < 26; i++)
        arr[i] = 0;

    arr[index] = 1;
    for(i = 0; i < size - 1; i++){
        j = i + 1;
        if(word[N][i] == word[N][j]) { //현재 인덱스와 다음 인덱스가 값이 같으면 arr[index]를 증가 시켜주고
            arr[index]++;
        }
        else { //만약 다르다면 arr[++index]++를 한다(인덱스를 증가시킨 다음에 요소값을 증가)
            arr[++index]++;
        }
    }

    not_zero_count = 0; //arr배열에서 요소값이 0이 아닌 것의 개수
    for(i = 0; i < 26; i++){
        if(arr[i] != 0)
            not_zero_count++;
    }

    if(alpha == not_zero_count) //알파벳의 종류 수와 not_zero_count가 같으면 연속적인 수
        return 1;
    else
        return 0;
}