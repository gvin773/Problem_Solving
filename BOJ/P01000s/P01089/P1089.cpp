#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int n;
string m[5];
vector<ll> v[10];
ll cnt = 1, sum;

void fun(int nth)
{
    bool imp[10] = {};

    int i = 0, j = 4*nth;
    if(m[i][j] == '#') imp[1] = true;
    if(m[i][j+1] == '#')
    {
        imp[1] = true;
        imp[4] = true;
    }

    if(m[i+1][j] == '#')
    {
        imp[1] = true;
        imp[2] = true;
        imp[3] = true;
        imp[7] = true;
    }
    if(m[i+1][j+1] == '#')
    {
        cout << -1;
        exit(0);
    }
    if(m[i+1][j+2] == '#')
    {
        imp[5] = true;
        imp[6] = true;
    }

    if(m[i+2][j] == '#')
    {
        imp[1] = true;
        imp[7] = true;
    }
    if(m[i+2][j+1] == '#')
    {
        imp[0] = true;
        imp[1] = true;
        imp[7] = true;
    }

    if(m[i+3][j] == '#')
    {
        imp[1] = true;
        imp[3] = true;
        imp[4] = true;
        imp[5] = true;
        imp[7] = true;
        imp[9] = true;
    }
    if(m[i+3][j+1] == '#')
    {
        cout << -1;
        exit(0);
    }
    if(m[i+3][j+2] == '#') imp[2] = true;

    if(m[i+4][j] == '#')
    {
        imp[1] = true;
        imp[4] = true;
        imp[7] = true;
    }
    if(m[i+4][j+1] == '#')
    {
        imp[1] = true;
        imp[4] = true;
        imp[7] = true;
    }

    for(int i = 0; i < 10; i++)
        if(!imp[i]) v[nth].push_back(i);
    cnt *= v[nth].size();
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < 5; i++) cin >> m[i];
    for(int i = 0; i < n; i++) fun(i);

    for(int i = 0; i < n; i++)
    {
        for(int j : v[i])
        {
            sum += (cnt/v[i].size() * j * pow(10, n-i-1));
        }
    }

    cout.precision(10);
    cout << fixed << sum / (long double)cnt;

    return 0;
}
