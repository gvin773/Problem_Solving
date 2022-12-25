#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll n;

int main()
{
    onlycc;
    cin >> n;
    cout << "int a;\n";
    for(int i = 1; i <= n; i++)
    {
        cout << "int ";
        for(int j = 0; j < i; j++) cout << "*";
        cout << "ptr";
        if(i > 1) cout << i;
        cout << " = &";
        if(i == 1)
        {
            cout << "a;\n";
            continue;
        }
        cout << "ptr";
        if(i > 2) cout << i-1;
        cout << ";\n";
    }

    return 0;
}
