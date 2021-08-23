#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
�� �Ǵ� ���� Ȧ���� ��� : ��� ������ ��ȸ�ϴ� ��θ� ���
��� ���� ��� ¦���� ��� : (r+c)%2==1�� ��(ü���� ����, ��������� ���� �ٸ� ��) �� ����� ���� ���� �� �����ϰ� ��ȸ
��ȸ ��� : 2ĭ ������ ���Ͼ���, �¿������ ��ġ�� 2*2�� �ǰ�, ������ ���� ��ǥ�� ���� RD �Ǵ� DR�� ���
*/

typedef long long ll;

int r, c, happy[1000][1000], m = 464646, tx, ty, x, y;
string tail;

int main()
{
    onlycc;
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            cin >> happy[i][j];
            if((i+j)%2 == 1 && happy[i][j] < m)
            {
                m = happy[i][j];
                tx = i, ty = j;
            }
        }

    if(r%2 == 1)
    {
        for(int i = 0; i < c-1; i++) cout << 'R';
        for(int i = 0; i < r-1; i++)
        {
            cout << 'D';
            if(i%2 == 0) for(int j = 0; j < c-1; j++) cout << 'L';
            else for(int j = 0; j < c-1; j++) cout << 'R';
        }
    }

    else if(c%2 == 1)
    {
        for(int i = 0; i < r-1; i++) cout << 'D';
        for(int i = 0; i < c-1; i++)
        {
            cout << 'R';
            if(i%2 == 0) for(int j = 0; j < r-1; j++) cout << 'U';
            else for(int j = 0; j < r-1; j++) cout << 'D';
        }
    }

    else
    {
        for(x = 0; x+2 < tx; x += 2)
        {
            for(int j = 0; j < c-1; j++) cout << 'R';
            cout << 'D';
            for(int j = 0; j < c-1; j++) cout << 'L';
            cout << 'D';
        }
        if(tx%2 == 0 && x+2 == tx)
        {
            for(int j = 0; j < c-1; j++) cout << 'R';
            cout << 'D';
            for(int j = 0; j < c-1; j++) cout << 'L';
            cout << 'D';
        }

        for(x = r-1; x-2 > tx; x -= 2)
        {
            tail.push_back('D');
            for(int j = 0; j < c-1; j++) tail.push_back('L');
            tail.push_back('D');
            for(int j = 0; j < c-1; j++) tail.push_back('R');
        }
        if(tx%2 == 1 && x-2 == tx)
        {
            tail.push_back('D');
            for(int j = 0; j < c-1; j++) tail.push_back('L');
            tail.push_back('D');
            for(int j = 0; j < c-1; j++) tail.push_back('R');
        }

        for(y = 0; y+2 < ty; y += 2) cout << "DRUR";
        if(ty%2 == 0 && y+2 == ty) cout << "DRUR";

        for(y = c-1; y-2 > ty; y -= 2) tail = "RURD" + tail;
        if(ty%2 == 1 && y-2 == ty) tail = "RURD" + tail;

        if(ty%2 == 1) cout << "DR";
        else cout << "RD";

        if(!tail.empty()) cout << tail;
    }

    return 0;
}
