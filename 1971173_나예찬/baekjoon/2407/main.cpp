#include <iostream>

int main()
{
    int a, b;
    scanf("%d %d",&a,&b);

    long long up=0, down=1;
    bool shifted = false;

    int sosu[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int total[25] = {0,};

    if(a>b){int tmp=a; a=b; b=tmp;}
    if(a/2<b){a=b-a;}


    for(int i=a+1; i<=b; ++i)
    {
        int n = i;
        for(int i=0;i<25;++i)
        {
            while(n%sosu[i]==0 && n>0)
            {
                n/=sosu[i];
                ++total[i];
            }
        }
    }
    for(int i=2; i<=b-a; ++i)
    {
        int n = i;
        for(int i=0;i<25;++i)
        {
            while(n%sosu[i]==0 && n>0)
            {
                n/=sosu[i];
                --total[i];
            }
        }
    }

    for(int i=0;i<25;++i)
    {
        for(int j=0;j<total[i];++j)
        {
            if(!shifted)
            {
                if(down < INT64_MAX / 100)
                {
                    down *= sosu[i];
                }
                else
                {
                    shifted = true;
                    up = down / 10000000000000000;
                    down %= 10000000000000000;

                    down *= sosu[i];
                    up *= sosu[i];

                    up += (down / 10000000000000000);
                    down %= 10000000000000000;
                }
            }
            else
            {
                down *= sosu[i];
                up *= sosu[i];

                up += (down / 10000000000000000);
                down %= 10000000000000000;
            }
        }
    }

    if(shifted)
    {
        printf("%lld%016lld",up,down);
    }
    else
    {
        printf("%lld",down);
    }
    
    return 0;
}