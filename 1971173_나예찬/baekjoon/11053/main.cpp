#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> data;
    data.reserve(n);

    vector<int> length = vector<int>(n, 0);

    for(int i=0;i<n;++i)
    {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }

    for(int i=n-1;i>=0;--i)
    {
        if(i==n-1) length[i]=1;
        else
        {
            length[i] = 1;
            for(int j=i+1;j<n;++j)
            {
                if(length[i] < length[j]+1 && data[i] < data[j])
                    length[i] = length[j]+1;
            }
        }
    }

    int max = -1;
    for(int i=0;i<n;++i)
    {
        if(max < length[i]) max = length[i];
    }
    cout << max << endl;
    return 0;
}