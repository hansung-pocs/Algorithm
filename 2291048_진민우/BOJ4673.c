#include <stdio.h>

int not_self_number(int n)
{
    int num = n;
    int sum = n;
    int r;

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
    int result;

    for(int i = 1; i < 10001; i++){
        result = not_self_number(i);
        if(result < 10001){
            a[result] = result;
        }
        if(a[i] == 0)
            printf("%d\n", i);
    }

    return 0;
}
