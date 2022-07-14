#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n/4; i++) cout << "long ";
    cout << "int";

    return 0;
}
