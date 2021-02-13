#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, s[100];

bool check(int i, int len)
{
    bool p = false;
    for(int j = 0; j < i; j++)
        if(s[len-1-j] != s[len-1-j-i]) p = true;
    return p;
} //p == true -> good

bool possible(int len)
{
    int t = len/2;
    for(int i = 1; i <= t; i++)
        if(!check(i, len)) return false;
    return true;
}

void track(int now)
{
    if(now == n)
    {
        for(int i = 0; i < n; i++)
            cout << s[i];
        exit(0);
    }

    s[now] = 1;
    if(possible(now+1)) track(now+1);
    s[now] = 0;

    s[now] = 2;
    if(possible(now+1)) track(now+1);
    s[now] = 0;

    s[now] = 3;
    if(possible(now+1)) track(now+1);
    s[now] = 0;
}

int main()
{
    onlycc;
    cin >> n;
    track(0);

    return 0;
}
