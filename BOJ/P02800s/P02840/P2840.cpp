#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, k, cnt, a;
char c[25];

int main()
{
    onlycc;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        c[i] = '?';

    for(int i = 0; i < k; i++)
    {
        int num;
        char x;
        cin >> num >> x;
        for(int j = 0; j < n; j++)
            if(c[j] == x && j != (cnt+num)%n) a = 1;

        cnt = (cnt+num)%n;
        if(c[cnt] == '?') c[cnt] = x;
        else if(c[cnt] != x) a = 1;
    }

    if(a)
    {
        cout << '!';
        return 0;
    }

    for(int i = cnt; i >= 0; i--)
        cout << c[i];

    for(int i = n-1; i > cnt; i--)
        cout << c[i];

    return 0;
}
