#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
    queue<int> q;
    int n;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        q.push(i);

    while(q.size() != 1)
    {
        q.pop();
        if(q.size() == 1) break;

        int a = q.front();
        q.push(a);
        q.pop();
    }

    printf("%d", q.front());

    return 0;
}
