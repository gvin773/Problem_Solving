#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <bitset>
using namespace std;

typedef long long ll;

int n, k, p[8];
bitset<1<<24> visited;
string s, fin;
queue<string> q;

int ind(string str)
{
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        int num = str[i]-'0'-1;
        index = index | (num<<(3*i));
    }
    return index;
}

string reverse_sort(string str, int x)
{
    string ret = str;
    for(int i = 0; i < k; i++) ret[x+i] = str[x+k-1-i];
    return ret;
}

int bfs()
{
    if(s == fin) return 0;
    q.push(s);
    visited[ind(s)] = true;

    int level = 0;
    while(!q.empty())
    {
        int Size = q.size();
        for(int i = 0; i < Size; i++)
        {
            string cur = q.front();
            if(cur == fin) return level;
            q.pop();

            for(int x = 0; x+k-1 < n; x++)
            {
                string p = reverse_sort(cur, x);
                if(!visited[ind(p)])
                {
                    q.push(p);
                    visited[ind(p)] = true;
                }
            }
        }
        level++;
    }

    return -1;
}

int main()
{
    onlycc;
    cin >> n >> k; s.resize(n), fin.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        fin[i] = '0'+i+1;
    }
    cout << bfs();

    return 0;
}
