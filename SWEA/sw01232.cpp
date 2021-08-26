#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;


int n, x, L, R, lc[1001], rc[1001];
string c;
pair<int, char> alpha[1001];

double get_ans(int now)
{
    if(alpha[now].first != -1) return (double)alpha[now].first;
    if(alpha[now].second == '+') return get_ans(lc[now]) + (double)get_ans(rc[now]);
    if(alpha[now].second == '-') return get_ans(lc[now]) - (double)get_ans(rc[now]);
    if(alpha[now].second == '*') return get_ans(lc[now]) * (double)get_ans(rc[now]);
    if(alpha[now].second == '/') return get_ans(lc[now]) / (double)get_ans(rc[now]);
}

int main()
{
    onlycc;
    for(int tc = 1; tc <= 10; tc++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            L = -1, R = -1;
            cin >> x >> c;
            if(c == "+" || c == "-" || c == "*" || c == "/")
            {
                cin >> L >> R;
                alpha[x] = {-1, c[0]};
            }
            else alpha[x] = {stoi(c), '!'};

            lc[x] = L;
            rc[x] = R;
        }

        cout << '#' << tc << ' ';

        cout << (int)get_ans(1);
        cout << '\n';
    }

    return 0;
}
