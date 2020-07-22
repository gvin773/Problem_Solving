#include <iostream>
#include <queue>
using namespace std;

queue<int> qf, qt;
int counter;

void hanoi(int n, int from, int by, int to)
{
    if(n == 1)
    {
        counter++;
        qf.push(from), qt.push(to);
    }

    else
    {
        hanoi(n-1, from, to, by);
        hanoi(1, from, by, to);
        hanoi(n-1, by, from, to);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    printf("%d\n", counter);
    while(!qt.empty())
    {
        printf("%d %d", qf.front(), qt.front());
        qf.pop(), qt.pop();
        puts("");
    }

    return 0;
}
