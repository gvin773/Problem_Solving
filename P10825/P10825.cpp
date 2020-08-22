#define onlycc ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<pair<int, int>, pair<int, string>> piiis;

int n;
pair<pair<int, int>, pair<int, string>> s[100000];

bool compare(const piiis& a, piiis& b)
{
    if(a.first.first == b.first.first)
    {
        if(a.first.second == b.first.second)
        {
            if(a.second.first == b.second.first)
                return a.second.second < b.second.second;

            return a.second.first > b.second.first;
        }

        return a.first.second < b.first.second;
    }

    return a.first.first > b.first.first;
}

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i].second.second >> s[i].first.first;
        cin >> s[i].first.second >> s[i].second.first;
    }

    sort(s, s+n, compare);
    for(int i = 0; i < n; i++)
        cout << s[i].second.second << '\n';

    return 0;
}
