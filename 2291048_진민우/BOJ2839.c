#include <stdio.h>

int main(void)
{
    int N;
    int three = 0;
    int five = 0;

    scanf("%d", &N);

    if(N % 5 == 0){ // 5로 딱 나누어 떨어지면 몫 반환
        five = N / 5;
        printf("%d", five);
    }
    else{ // N % 5 != 0
        while(N > 0){
            if(N % 5 != 0){ // 5로 나눈 나머지가 0이 아니면
                N -= 3; //3을 뺀다
                three++; //빼면 3kg의 봉지 수는 증가
            }
            else{ // 5로 나눈 나머지가 0이면
                N -= 5; //5를 뺀다
                five++; //빼면 5kg 봉지 수는 증가
            }
        }
        if(N < 0){ //만약 계속 빼다가 0보다 작아지면, 나누어 떨어진게 아니므로 -1반환
            printf("-1");
        }
        else{ //계속 빼다가 n이 0이 될 때, 나누어 떨어진 것임
            printf("%d", five + three);
        }
    }

    return 0;
}