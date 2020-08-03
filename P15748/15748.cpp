#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    long long L, N, r_F, r_B;
    long long ret = 0;
    pair<long long, long long> rest[100000];

    scanf("%lld%lld%lld%lld", &L, &N, &r_F, &r_B);
    for(int i = 0; i < N; i++)
    {
        long long x, c;
        scanf("%lld%lld", &x, &c);
        rest[i] = make_pair(c, x);
    }

    sort(rest, rest+N);

    long long now = 0;
    for(int i = N-1; i >= 0; i--)
    {
        if(rest[i].second > now)
        {
            long long d = rest[i].second - now;
            ret += (r_F-r_B)*d*rest[i].first;
            now = rest[i].second;
        }
    }

    printf("%lld", ret);

    return 0;
}
