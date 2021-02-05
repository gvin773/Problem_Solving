#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int l, c, cnt_vow, cnt_con;
char a[15];

void dfs(int now, int len, string str)
{
    if(len == l || now == c)
    {
        if(len == l && cnt_vow >= 1 && cnt_con >= 2) cout << str << '\n';
        return;
    }

    if(a[now] == 'a' || a[now] == 'e' || a[now] == 'i' || a[now] == 'o' || a[now] == 'u')
    {
        cnt_vow++;
        str[len] = a[now];
        dfs(now+1, len+1, str);
        cnt_vow--;

        dfs(now+1, len, str);
    }

    else
    {
        cnt_con++;
        str[len] = a[now];
        dfs(now+1, len+1, str);
        cnt_con--;

        dfs(now+1, len, str);
    }
}

int main()
{
    onlycc;
    cin >> l >> c;
    for(int i = 0; i < c; i++) cin >> a[i];
    sort(a, a+c);
    string str;
    str.resize(l);
    dfs(0, 0, str);

    return 0;
}
