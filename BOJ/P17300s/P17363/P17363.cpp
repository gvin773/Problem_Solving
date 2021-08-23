#include <iostream>
using namespace std;

int main()
{
    int n, m;
    char arr[101][101];
    char left[101][101];

    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            left[i][j] = arr[j][m-1-i];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            if(left[i][j] == '-')
                left[i][j] = '|';

            else if(left [i][j] == '|')
                left[i][j] = '-';

            else if(left [i][j] == '/')
                left[i][j] = '\\';

            else if(left [i][j] == '\\')
                left[i][j] = '/';

            else if(left [i][j] == '^')
                left[i][j] = '<';

            else if(left [i][j] == '<')
                left[i][j] = 'v';

            else if(left [i][j] == 'v')
                left[i][j] = '>';

            else if(left [i][j] == '>')
                left[i][j] = '^';
        }

    for(int i = 0; i < m; i++)
        left[i][n] = '\0';

    for(int i = 0; i < m; i++)
        printf("%s\n", left[i]);

    return 0;
}
