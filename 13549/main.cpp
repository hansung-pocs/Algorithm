#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> time = vector<int>(200001, -1);
    time[n] = 0;

    queue<int> _queue, nextQueue;

    _queue.push(n);

    while(true)
    {
        while(!_queue.empty())
        {
            int pos = _queue.front();
            int tmp = pos;
            if(tmp == k)
            {
                nextQueue = queue<int>();
                break;
            }
            while(tmp<=200000 && tmp>0)
            {
                if(time[tmp] == -1 || time[tmp] > time[pos])
                {
                    nextQueue.push(tmp);
                    time[tmp] = time[pos];
                }
                tmp*=2;
            }
            tmp=pos;
            if(tmp>0 && (time[tmp-1] == -1 || time[tmp-1] > time[tmp] + 1))
            {
                nextQueue.push(tmp-1);
                time[tmp-1] = time[tmp] + 1;
            }
            if(n<200000 && (time[tmp+1] == -1 || time[tmp+1] > time[tmp] + 1))
            {
                nextQueue.push(tmp+1);
                time[tmp+1] = time[tmp] + 1;
            }
            _queue.pop();
        }

        _queue = nextQueue;

        if(_queue.size() == 0) break;

        nextQueue = queue<int>();
    }

    cout << time[k] << endl;
}