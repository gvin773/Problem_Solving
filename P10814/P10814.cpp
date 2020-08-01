#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

pair<int, string> data[100000], sorted[100001];
int age[201];

int main()
{
    int n;
    scanf("%d", &n);

    int minv = 987654321;
    for(int i = 0; i < n; i++)
    {
        int a;
        string str;
        cin >> a >> str;
        minv = min(minv, a);
        age[a]++;
        data[i] = make_pair(a, str);
    }

    int temp = age[minv];
    for(int i = minv+1; i <= 200; i++)
    {
        if(age[i] != 0)
        {
            age[i] += temp;
            temp = age[i];
        }
    }

    for(int i = n-1; i >= 0; i--)
        sorted[age[data[i].first]--] = data[i];

    for(int i = 1; i <= n; i++)
        cout << sorted[i].first << " " << sorted[i].second << '\n';

    return 0;
}
