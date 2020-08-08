#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    vector<int> v;
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++)
        v.push_back(i);

    printf("<");
    int cnt = 1;
    for(vector<int>::iterator iter = v.begin(); v.size() != 0;)
    {
        if(iter == v.end()) iter = v.begin();

        if(cnt == k)
        {
            cnt = 1;
            if(v.size() == 1) printf("%d>", *iter);
            else printf("%d, ", *iter);
            iter = v.erase(iter);
        }

        else
        {
            cnt++;
            iter++;
        }
    }

    return 0;
}
