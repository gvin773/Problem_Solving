#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int n;

void f(int x)
{
    for(int i = 0; i < x; i++) cout << "____";
}

void print(int x)
{
    f(x);
    cout << "\"����Լ��� ������?\"\n";
    if(x != n)
    {
        f(x);
        cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        f(x);
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        f(x);
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        print(x+1);
    }
    else
    {
        f(x);
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }

    f(x);
    cout << "��� �亯�Ͽ���.\n";
}

int main()
{
    onlycc;
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    print(0);

    return 0;
}
