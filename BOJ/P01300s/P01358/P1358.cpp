#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll w, h, x, y, p, px, py, ans;

int d(int a,int b, int c, int d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}

int main()
{
    onlycc;
    cin >> w >> h >> x >> y >> p;
    for(int i = 0; i < p; i++)
    {
        cin >> px >> py;
        if(x-h/2 <= px && px <= x && y <= py && py <= y+h && d(px,py,x,y+h/2) <= h*h/4) ans++;
        else if(x <= px && px <= x+w && y <= py && py <= y+h) ans++;
        else if(x+w <= px && px <= x+w+h/2 && y <= py && py <= y+h && d(px,py,x+w,y+h/2) <= h*h/4) ans++;
    }
    cout << ans;

    return 0;
}
