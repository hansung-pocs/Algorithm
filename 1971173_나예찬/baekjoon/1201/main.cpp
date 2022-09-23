#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nmk(int n, int m, int k, vector<int> & num)
{
    auto itr = num.begin();
    if(m*k < n || m+k-1 > n)
    {
        cout << "-1" << endl;
        return;
    }

    reverse(itr, itr+k);
    n-=k;
    --m;
    itr+=k;

    while(m>0)
    {
        int amount = n-m+1;

        if(amount > k) amount = k;

        reverse(itr, itr+amount);
        n-=amount;
        --m;
        itr+=amount;
    }
    for(auto & e : num) cout << e << " ";
    cout << endl;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> num;
    num.reserve(n);

    for(int i=1;i<=n;++i) num.push_back(i);

    nmk(n,m,k,num);

    return 0;
}