#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

typedef long long ll;

int n, a[1000000];
deque<int> d;

int main()
{
    onlycc;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n-1, cnt = 1; i >= 0; i--)
    {
        if(a[i] == 1)
        {
            d.push_front(cnt);
        }
        else if(a[i] == 2)
        {
            int temp = *d.begin();
            d.pop_front();
            d.push_front(cnt);
            d.push_front(temp);
        }
        else
        {
            d.push_back(cnt);
        }
        cnt++;
    }
    while(!d.empty())
    {
        cout << *d.begin() << ' ';
        d.pop_front();
    }

    return 0;
}
