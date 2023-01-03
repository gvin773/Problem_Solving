#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

ll tc, a, b, c, d;

int main()
{
    onlycc;
	cin >> tc;
	while(tc--)
    {
		cin >> a >> b >> c >> d;
		if(a*b == c*d) cout << "Tie\n";
		else cout << (a*b < c*d ? "Eurecom\n" : "TelecomParisTech\n");
	}

	return 0;
}
