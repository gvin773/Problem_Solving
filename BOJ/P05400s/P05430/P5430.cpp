#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
using namespace std;

typedef long long ll;

int t, n;
string p, arr;

int main()
{
    onlycc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        deque<int> d;
        cin >> p >> n >> arr;

        int now = 0;
        for(int j = 0; j < n-1; j++) //[ , , ,
        {
            int num = 0;
            int temp = arr.find(",", now+1), mul = (int)pow(10,temp-now-2);
            for(int k = now+1; k < temp; k++)
            {
                num += (arr[k]-'0')*mul;
                mul /= 10;
            }
            now = temp;
            d.push_back(num);
        }

        int temp = arr.find("]", now+1), mul = (int)pow(10, temp-now-2), num = 0;
        for(int k = now+1; k < temp; k++) //, ]
        {
            num += (arr[k]-'0')*mul;
            mul /= 10;
        }
        if(n != 0) d.push_back(num);

        int cnt = 0; //0, 1, 2 == error
        for(int j = 0; j < p.size(); j++)
        {
            if(p[j] == 'R') cnt = (cnt+1)%2;
            else
            {
                if(d.empty())
                {
                    cnt = 2;
                    break;
                }
                if(cnt == 0) d.pop_front();
                else d.pop_back();
            }
        }

        if(cnt == 2) cout << "error\n";
        else if(d.empty()) cout << "[]\n";
        else if(d.size() == 1) cout << '[' << d.front() << "]\n";
        else
        {
            cout << '[';
            while(d.size() != 1)
            {
                if(cnt == 0)
                {
                    cout << d.front() << ',';
                    d.pop_front();
                }
                else
                {
                    cout << d.back() << ',';
                    d.pop_back();
                }
            }

            cout << d.front() << "]\n";
        }
    }

    return 0;
}
