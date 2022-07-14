#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n;
char x, L[50], R[50];

void f1(char now)
{
    cout << now;
    if(L[now-'A'] != '.') f1(L[now-'A']);
    if(R[now-'A'] != '.') f1(R[now-'A']);
}

void f2(char now)
{
    if(L[now-'A'] != '.') f2(L[now-'A']);
    cout << now;
    if(R[now-'A'] != '.') f2(R[now-'A']);
}

void f3(char now)
{
    if(L[now-'A'] != '.') f3(L[now-'A']);
    if(R[now-'A'] != '.') f3(R[now-'A']);
    cout << now;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        cin >> L[x-'A'] >> R[x-'A'];
    }

    f1('A');
    cout << '\n';
    f2('A');
    cout << '\n';
    f3('A');

    return 0;
}
