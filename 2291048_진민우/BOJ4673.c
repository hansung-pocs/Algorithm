#include <stdio.h>

int self_number(int n)
{
    int num = n;
    int sum = n;
    int r = 0;

    while(num > 0){
        r = num % 10;
        num = num / 10;
        sum += r;
    }
    return sum;
}

int main(void)
{
    int a[10001] = {0};
    int num;

    for(int i = 1; i < 10001; i++){
        num = self_number(i);
        if(num < 10001){
            a[num] = num;
        }
    }

    for(int i = 1; i < 10001; i++){
        if(a[i] == 0){
            printf("%d\n", i);
        }
    }

    return 0;
}