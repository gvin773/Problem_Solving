#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;
    if(s[n-1]=='q'||s[n-1]=='w'||s[n-1]=='e'||s[n-1]=='r'||s[n-1]=='t') cout << 1;
    else if(s[n-1]=='a'||s[n-1]=='s'||s[n-1]=='d'||s[n-1]=='f'||s[n-1]=='g') cout << 1;
    else if(s[n-1]=='z'||s[n-1]=='x'||s[n-1]=='c'||s[n-1]=='v') cout << 1;
    else cout << 0;
    return 0;
}
