#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int n, cnt = 10;
string now = "10";

int main()
{
    onlycc;
    cin >> n;
    if(n <= 10) cout << n;
    else
    {
        while(cnt < n && now != "9876543210")
        {
            int i = now.size()-1;
            while(i != 0  && now[i]+1 >= now[i-1]) i--;

            if(i != 0) now[i]++;
            else if(now[i] != '9') now[i]++;
            else now = "1" + now;

            for(int j = i+1; j < now.size(); j++) now[j] = '0';

            int flag = 0;
            for(int j = 0; j < now.size(); j++) if(now[j] == '0') flag++;
            if(flag <= 1) cnt++;
        }

        cout << (cnt == n ? now : "-1");
    }

    return 0;
}
