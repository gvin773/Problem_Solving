#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string n;

int main()
{
    onlycc;
    cin >> n;
    cout << pow(n[0]-'0',5) + pow(n[1]-'0',5) + pow(n[2]-'0',5) + pow(n[3]-'0',5) + pow(n[4]-'0',5);

    return 0;
}
