#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, X, Y;
vector<pll> robot, target;

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    ll ret = x1*y2 - x2*y1;
    return ret == 0 ? 0 : (ret > 0 ? 1 : -1);
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> X >> Y;
        robot.push_back({X, Y});
    }
    for(int i = 0; i < n; i++)
    {
        cin >> X >> Y;
        target.push_back({X, Y});
    }

    vector<ll> idx(n);
    for(int i = 0; i < n; i++) idx[i] = i+1;

    do
    {
        vector<pair<pll, pll>> line(n);
        for(int i = 0; i < n; i++) line[i] = make_pair(robot[i], target[idx[i]-1]);

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                auto before = line[i], now = line[j];

                ll x1 = before.first.first, y1 = before.first.second, x2 = before.second.first, y2 = before.second.second;
                ll a = now.first.first, b = now.first.second, c = now.second.first, d = now.second.second;

                if(x2 < x1 || (x1 == x2 && y2 < y1))
                {
                    swap(x1, x2);
                    swap(y1, y2);
                }

                if(c < a || (a == c && d < b))
                {
                    swap(a, c);
                    swap(b, d);
                }

                if(a < x1 || (a == x1 && b < y1))
                {
                    swap(x1, a);
                    swap(y1, b);
                    swap(x2, c);
                    swap(y2, d);
                }

                if(x1 == x2 && x2 == a && a == c)
                {
                    if(y2 >= b) goto over;
                    else continue;
                }
                else if((y2-y1)*(a-x2) == (b-y2)*(x2-x1) && (b-y2)*(c-a) == (d-b)*(a-x2))
                {
                    if(x2 >= a) goto over;
                    else continue;
                }
                else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(c-a, d-b, x1-c, y1-d) * cross(c-a, d-b, x2-c, y2-d) <= 0) goto over;
            }
        }
        for(int i = 0; i < n; i++) cout << idx[i] << '\n';
        return 0;

        over:;
    }while(next_permutation(idx.begin(), idx.end()));

    return 0;
}
