#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

string str[5], in, ans;

int main()
{
    onlycc;
    for(int i = 0; i < 5; i++) str[i] = "!!!!!!!!!!!!!!!";
    for(int i = 0; i < 5; i++)
    {
        cin >> in;
        for(int j = 0; j < in.size(); j++) str[i][j] = in[j];
    }

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(str[j][i] != '!') ans.push_back(str[j][i]);
        }
    }

    cout << ans;

    return 0;
}
