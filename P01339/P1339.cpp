#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, ans, first[30], cnt;
string w[10];
pair<int, char> alpha[30];

int main()
{
    onlycc;
    cin >> n;
    for(int i = 'A'; i <= 'Z'; i++)
        alpha[i-'A'].second = i;

    for(int i = 0; i < n; i++)
    {
        cin >> w[i];

        int m = 1;
        for(int j = (int)w[i].size()-1; j >= 0; j--)
        {
            alpha[w[i][j] - 'A'].first += m;
            m *= 10;
            if(j == 0 && w[i].size() != 1) first[w[i][j] - 'A'] = true;
        }
    }

    for(int i = 0; i < 30; i++)
        if(alpha[i].first > 0) cnt++;
    sort(alpha, alpha+30);

    if(cnt != 10)
    {
        for(int i = 0; i < cnt; i++)
            ans += (9-i)*alpha[29-i].first;
    }

    else
    {
        int zero = 464646;
        for(int i = 0; i < 30; i++)
        {
            if(alpha[i].first > 0 && first[alpha[i].second - 'A'] != true)
            {
                zero = i;
                break;
            }
        }

        int num = 9;
        for(int i = 29; i > 29 - cnt; i--)
        {
            if(i != zero)
            {
                ans += num*alpha[i].first;
                num--;
            }
        }
    }

    cout << ans;
    return 0;
}
