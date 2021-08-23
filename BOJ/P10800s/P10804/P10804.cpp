#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int a, b, arr[21], temp[21];

int main()
{
    onlycc;
    for(int i = 1; i <= 20; i++) arr[i] = i;
    for(int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        for(int j = a; j <= b; j++) temp[j] = arr[j];
        for(int j = 0; j < b-a+1; j++) arr[a+j] = temp[b-j];
    }
    for(int i = 1; i <= 20; i++) cout << arr[i] << ' ';

    return 0;
}
