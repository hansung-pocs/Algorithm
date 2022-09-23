#include <iostream>

using namespace std;

int main()
{
    bool arr[10][10];

    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            arr[i][j] = getchar()=='O';
        }
        getchar();
    }

    




    return 0;
}