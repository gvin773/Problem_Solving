#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

ll n, num[30];
string a, b, c, d;

int main()
{
    onlycc;
    cin >> n;
    cin >> a >> b;
    if(a[0] != b[0] || a[n-1] != b[n-1])
    {
        cout << "NO";
        goto fin;
    }
    for(int i = 0; i < n; i++)
    {
        num[a[i]-'a']++;
        num[b[i]-'a']--;
    }
    for(int i = 0; i < 30; i++)
    {
        if(num[i])
        {
            cout << "NO";
            goto fin;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u') c.push_back(a[i]);
        if(b[i] != 'a' && b[i] != 'e' && b[i] != 'i' && b[i] != 'o' && b[i] != 'u') d.push_back(b[i]);
    }
    if(c == d) cout << "YES";
    else cout << "NO";

    fin:;

    return 0;
}
