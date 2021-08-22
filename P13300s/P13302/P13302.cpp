#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[101][101] = { 0 };
bool xday[101]; //0 means can go

int minvalue(int day, int coupon)
{
    if(day > n) return 0;

    int &cost = dp[day][coupon];

    if(cost != 0) return cost;

    if(xday[day]) cost = minvalue(day+1, coupon);

    else
    {
        cost = minvalue(day+1, coupon) + 10000;
        cost = min(cost, minvalue(day+3, coupon+1) + 25000);
        cost = min(cost, minvalue(day+5, coupon+2) + 37000);

        if(coupon >= 3)
            cost = min(cost, minvalue(day+1, coupon-3));
    }

    return cost;
}

int main()
{
    int i, j, x;

    scanf("%d%d", &n, &m);

    for(i = 0; i < m; i++)
    {
        scanf("%d", &x);
        xday[x] = true; //1 means cannot go
    }

    printf("%d", minvalue(1, 0));

    return 0;
}

