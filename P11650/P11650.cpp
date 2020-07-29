#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> coord;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        coord.push_back(pair<int, int>(a, b));
    }

    sort(coord.begin(),coord.end());

    for(vector<pair<int, int>> ::iterator iter = coord.begin(); iter < coord.end(); iter++)
        printf("%d %d\n", iter->first, iter->second);
}
