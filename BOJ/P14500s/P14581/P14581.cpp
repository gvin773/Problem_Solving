#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string id;

int main()
{
    onlycc;
    cin >> id;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == 1 && j == 1) cout << ':' << id << ':';
            else cout << ":fan:";
        }
        cout << '\n';
    }

    return 0;
}
