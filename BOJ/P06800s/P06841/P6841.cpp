#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, long double> pid;

string s;

int main()
{
    onlycc;
    while(cin >> s)
    {
        if(s == "CU") cout << "see you\n";
        else if(s == ":-)") cout << "I¡¯m happy\n";
        else if(s == ":-(") cout << "I¡¯m unhappy\n";
        else if(s == ";-)") cout << "wink\n";
        else if(s == ":-P") cout << "stick out my tongue\n";
        else if(s == "(~.~)") cout << "sleepy\n";
        else if(s == "TA") cout << "totally awesome\n";
        else if(s == "CCC") cout << "Canadian Computing Competition\n";
        else if(s == "CUZ") cout << "because\n";
        else if(s == "TY") cout << "thank-you\n";
        else if(s == "YW") cout << "you¡¯re welcome\n";
        else if(s == "TTYL") cout << "talk to you later\n";
        else cout << s << '\n';
    }

    return 0;
}
