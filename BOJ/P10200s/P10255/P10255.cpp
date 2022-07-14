#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll cross(ll x1, ll y1, ll x2, ll y2)
{
    return x1*y2 - x2*y1;
}

bool check(ll x1, ll y1, ll x2, ll y2, ll a, ll b)
{
    return (cross(x2-x1, y2-y1, a-x2, b-y2) == 0) && (x1 <= a && a <= x2 && ((y1 <= b && b <= y2) || (y2 <= b && b <= y1)));
}

ll my_solution(ll a, ll b, ll c, ll d, ll x1, ll y1, ll x2, ll y2)
{
        if(x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        if(x1 == x2 && y1 > y2) swap(y1, y2);
        if(y1 == y2 && x1 > x2) swap(x1, x2);

        if(max(x1, x2) < a || c < min(x1, x2)) return 0;
        if(max(y1, y2) < b || d < min(y1, y2)) return 0;

        if(x1 == x2 && y1 != y2 && ((y1 <= b && b <= y2 && y1 <= d && d <= y2) || (b <= y1 && y1 <= d && b <= y2 && y2 <= d) || (b < y1 && y1 < d) || (b < y2 && y2 < d)) && (x1 == a || x1 == c))
        {
            return 4;
        }
        if(x1 != x2 && y1 == y2 && ((x1 <= a && a <= x2 && x1 <= c && c <= x2) || (a <= x1 && x1 <= c && a <= x2 && x2 <= c) || (a < x1 && x1 < c) || (a < x2 && x2 < c)) && (y1 == b || y1 == d))
        {
            return 4;
        }

        if(check(x1, y1, x2, y2, a, b)) //LD
        {
            if(check(x1, y1, x2, y2, c, d))
            {
                return 2;
            }
            else if(cross(x2-x1, y2-y1, a-x2, d-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(c-a, 0, x1-c, y1-d) * cross(c-a, 0, x2-c, y2-d) <= 0)
            {
                return 2;
            }
            else if(cross(x2-x1, y2-y1, c-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(0, d-b, x1-c, y1-d) * cross(0, d-b, x2-c, y2-d) <= 0)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }

        if(check(x1, y1, x2, y2, a, d)) //LU
        {
            if(check(x1, y1, x2, y2, c, b))
            {
                return 2;
            }
            else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, b-y2) <= 0 && cross(c-a, 0, x1-c, y1-b) * cross(c-a, 0, x2-c, y2-b) <= 0)
            {
                return 2;
            }
            else if(cross(x2-x1, y2-y1, c-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(0, d-b, x1-c, y1-d) * cross(0, d-b, x2-c, y2-d) <= 0)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }

        if(check(x1, y1, x2, y2, c, d)) //RU
        {
            if(check(x1, y1, x2, y2, a, b))
            {
                return 2;
            }
            else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, b-y2) <= 0 && cross(c-a, 0, x1-c, y1-b) * cross(c-a, 0, x2-c, y2-b) <= 0)
            {
                return 2;
            }
            else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, a-x2, d-y2) <= 0 && cross(0, d-b, x1-a, y1-d) * cross(0, d-b, x2-a, y2-d) <= 0)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }

        if(check(x1, y1, x2, y2, c, b)) //RD
        {
            if(check(x1, y1, x2, y2, a, d))
            {
                return 2;
            }
            else if(cross(x2-x1, y2-y1, a-x2, d-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(c-a, 0, x1-c, y1-d) * cross(c-a, 0, x2-c, y2-d) <= 0)
            {
                return 2;
            }
            else if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, a-x2, d-y2) <= 0 && cross(0, d-b, x1-a, y1-d) * cross(0, d-b, x2-a, y2-d) <= 0)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }

        int cnt = 0;
        if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, a-x2, d-y2) <= 0 && cross(0, d-b, x1-a, y1-d) * cross(0, d-b, x2-a, y2-d) <= 0) cnt++; //L
        if(cross(x2-x1, y2-y1, c-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(0, d-b, x1-c, y1-d) * cross(0, d-b, x2-c, y2-d) <= 0) cnt++; //R
        if(cross(x2-x1, y2-y1, a-x2, d-y2) * cross(x2-x1, y2-y1, c-x2, d-y2) <= 0 && cross(c-a, 0, x1-c, y1-d) * cross(c-a, 0, x2-c, y2-d) <= 0) cnt++; //U
        if(cross(x2-x1, y2-y1, a-x2, b-y2) * cross(x2-x1, y2-y1, c-x2, b-y2) <= 0 && cross(c-a, 0, x1-c, y1-b) * cross(c-a, 0, x2-c, y2-b) <= 0) cnt++; //D

        return cnt;
    return 0;
}

int main()
{
    onlycc;
    ll tc, a, b, c, d, x1, y1, x2, y2;
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b >> c >> d;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << my_solution(a, b, c, d, x1, y1, x2, y2) << '\n';
    }

    return 0;
}
