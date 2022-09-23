#include <iostream>

using namespace std;

struct matrix2x2{
    long long arr[2][2];

    matrix2x2(long long e11, long long e12, long long e21, long long e22)
    {
        arr[0][0] = e11;
        arr[0][1] = e12;
        arr[1][0] = e21;
        arr[1][1] = e22;
    }

    const matrix2x2 operator *(const matrix2x2 & other)
    {
        return matrix2x2(
            (arr[0][0] * other.arr[0][0] + arr[0][1] * other.arr[1][0])%1000000007, 
            (arr[0][0] * other.arr[0][1] + arr[0][1] * other.arr[1][1])%1000000007, 
            (arr[1][0] * other.arr[0][0] + arr[1][1] * other.arr[1][0])%1000000007, 
            (arr[1][0] * other.arr[0][1] + arr[1][1] * other.arr[1][1])%1000000007
        );
    }

    static matrix2x2 power(matrix2x2 mat, long long n)
    {
        if(n == 0) return matrix2x2(1, 0, 0, 1);
        if(n == 1) return mat;
        if(n%2 == 1) return mat * matrix2x2::power(mat, n-1);
        else
        {
            matrix2x2 smallMat = matrix2x2::power(mat, n/2);
            return smallMat * smallMat;
        }
    }

    long long get(long long i, long long j){return arr[i][j];}
};

int main()
{
    long long n;

    cin >> n;

    cout << matrix2x2::power(matrix2x2(1,1,1,0), n-1).get(0,0) << endl;


    return 0;
}