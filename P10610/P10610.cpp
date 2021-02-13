#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

string n;
int s;
bool p;
vector<int> v;

bool compare(int i, int j) {return i > j; }

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n.size(); i++)
    {
        s += (n[i] - '0');
        if(n[i] == '0') p = true;
        v.push_back(n[i] - '0');
    }

    if(s % 3 != 0 || p != true) cout << -1;
    else
    {
        sort(v.begin(), v.end(), compare);
        for(int i : v) cout << i;
    }

    return 0;
}
