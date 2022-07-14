#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n, s;

int main()
{
    //onlycc;
    while(scanf("%d%d", &n, &s) != EOF)
    {
        printf("%lld\n", s/(n+1));
    }

    return 0;
}
