#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;

/*
목표와 마주보는 경우, 같은 라인에 있는 경우, 옆에 있는 경우를 나누어 해결한다.
*/

int n, m, t, x[100], y[100], sx, sy, ans;

int main()
{
    onlycc;
    cin >> n >> m >> t;
    for(int i = 0; i < t; i++) cin >> x[i] >> y[i];
    cin >> sx >> sy;

    for(int i = 0; i < t; i++)
    {
        if((sx==1 && x[i]==2) || (sx==2 && x[i]==1)) ans += min(sy+m+y[i], n-sy+m+n-y[i]);
        else if((sx==3 && x[i]==4) || (sx==4 && x[i]==3)) ans += min(sy+n+y[i], m-sy+n+m-y[i]);
        else if(sx == x[i]) ans += abs(sy-y[i]);
        else if(sx == 1)
        {
            if(x[i] == 3) ans += y[i]+sy;
            else ans += y[i]+n-sy;
        }
        else if(sx == 2)
        {
            if(x[i] == 3) ans += m-y[i]+sy;
            else ans += m-y[i]+n-sy;
        }
        else if(sx == 3)
        {
            if(x[i] == 1) ans += y[i]+sy;
            else ans += y[i]+m-sy;
        }
        else
        {
            if(x[i] == 1) ans += n-y[i]+sy;
            else ans += n-y[i]+m-sy;
        }
    }

    cout << ans;

    return 0;
}
