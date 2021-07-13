#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n, q, y, z, pSum[26][200001];
char x;
string s;

int main()
{
    onlycc;
    cin >> s >> q;
    for(int i = 0; i < s.size(); i++) for(int j = 0; j < 26; j++)
            pSum[j][i+1] = pSum[j][i] + (s[i] == (j+'a') ? 1 : 0);
    for(int i = 0; i < q; i++)
    {
        cin >> x >> y >> z;
        cout << pSum[x-'a'][z+1] - pSum[x-'a'][y] << '\n';
    }

    return 0;
}
