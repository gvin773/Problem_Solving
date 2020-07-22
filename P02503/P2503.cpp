#include <cstdio>
using namespace std;

int n, num[100], strike[100], ball[100];
bool ret[1000];
int counter;

void check()
{
    for(int i = 100; i <= 999; i++)
    {
        counter = 0;
        for(int j = 0; j < n; j++)
        {
            int d[4], temp = num[j], x = 3;//ex. 352 -> d[1] = 3, d[2] = 5, d[3] = 2
            while(temp)
            {
                d[x--] = temp % 10;
                temp /= 10;
            }

            int r[4], temp2 = i, x2 = 3;
            while(temp2)
            {
                r[x2--] = temp2 % 10;
                temp2 /= 10;
            }

            if(strike[j] == 0 && ball[j] == 0)
            {
                if(r[1] == d[1] || r[1] == d[2] || r[1] == d[3] || r[2] == d[1] || r[2] == d[2] || r[2] == d[3] || r[3] == d[1] || r[3] == d[2] || r[3] == d[3])
                    break;
                else counter++;
            }

            else if(strike[j] == 0 && ball[j] == 1)
            {
                int c = 0;
                for(int q = 1; q <= 3; q++)
                    if(d[q] == r[q])
                        c++;

                if(c != 0) break;

                c = 0;
                for(int q = 2; q <= 3; q++)
                    if(r[1] == d[q])
                        c++;

                for(int q = 3; q >= 1; q -= 2)
                    if(r[2] == d[q])
                        c++;

                for(int q = 1; q <= 2; q++)
                    if(r[3] == d[q])
                        c++;

                if(c != 1) break;
                else counter++;
            }

            else if(strike[j] == 0 && ball[j] == 2)
            {
                int c = 0;
                for(int q = 1; q <= 3; q++)
                    if(d[q] == r[q])
                        c++;

                if(c != 0) break;

                c = 0;
                for(int q = 2; q <= 3; q++)
                    if(r[1] == d[q])
                        c++;

                for(int q = 3; q >= 1; q -= 2)
                    if(r[2] == d[q])
                        c++;

                for(int q = 1; q <= 2; q++)
                    if(r[3] == d[q])
                        c++;

                if(c != 2) break;
                else counter++;
            }

            else if(strike[j] == 0 && ball[j] == 3)
            {
                int c = 0;
                for(int q = 1; q <= 3; q++)
                    if(d[q] == r[q])
                        c++;

                if(c != 0) break;

                c = 0;
                for(int q = 2; q <= 3; q++)
                    if(r[1] == d[q])
                        c++;

                for(int q = 3; q >= 1; q -= 2)
                    if(r[2] == d[q])
                        c++;

                for(int q = 1; q <= 2; q++)
                    if(r[3] == d[q])
                        c++;

                if(c != 3) break;
                else counter++;
            }

            else if(strike[j] == 1 && ball[j] == 0)
            {
                int c = 0;
                for(int q = 1; q <= 3; q++)
                    if(d[q] == r[q])
                        c++;

                if(c != 1) break;

                c = 0;
                for(int q = 2; q <= 3; q++)
                    if(r[1] == d[q])
                        c++;

                for(int q = 3; q >= 1; q -= 2)
                    if(r[2] == d[q])
                        c++;

                for(int q = 1; q <= 2; q++)
                    if(r[3] == d[q])
                        c++;

                if(c != 0) break;
                else counter++;
            }

            else if(strike[j] == 1 && ball[j] == 1)
            {
                int c = 0;
                for(int q = 1; q <= 3; q++)
                    if(d[q] == r[q])
                        c++;

                if(c != 1) break;

                c = 0;
                for(int q = 2; q <= 3; q++)
                    if(r[1] == d[q])
                        c++;

                for(int q = 3; q >= 1; q -= 2)
                    if(r[2] == d[q])
                        c++;

                for(int q = 1; q <= 2; q++)
                    if(r[3] == d[q])
                        c++;

                if(c != 1) break;
                else counter++;
            }

            else if(strike[j] == 1 && ball[j] == 2)
            {
                int c = 0;
                for(int q = 1; q <= 3; q++)
                    if(d[q] == r[q])
                        c++;

                if(c != 1) break;

                c = 0;
                for(int q = 2; q <= 3; q++)
                    if(r[1] == d[q])
                        c++;

                for(int q = 3; q >= 1; q -= 2)
                    if(r[2] == d[q])
                        c++;

                for(int q = 1; q <= 2; q++)
                    if(r[3] == d[q])
                        c++;

                if(c != 2) break;
                else counter++;
            }

            else if(strike[j] == 2 && ball[j] == 0)
            {
                int c = 0;
                for(int q = 1; q <= 3; q++)
                    if(d[q] == r[q])
                        c++;

                if(c != 2) break;

                c = 0;
                for(int q = 2; q <= 3; q++)
                    if(r[1] == d[q])
                        c++;

                for(int q = 3; q >= 1; q -= 2)
                    if(r[2] == d[q])
                        c++;

                for(int q = 1; q <= 2; q++)
                    if(r[3] == d[q])
                        c++;

                if(c != 0) break;
                else counter++;
            }

            else if(strike[j] == 2 && ball[j] == 1)
            {
                int c = 0;
                for(int q = 1; q <= 3; q++)
                    if(d[q] == r[q])
                        c++;

                if(c != 2) break;

                c = 0;
                for(int q = 2; q <= 3; q++)
                    if(r[1] == d[q])
                        c++;

                for(int q = 3; q >= 1; q -= 2)
                    if(r[2] == d[q])
                        c++;

                for(int q = 1; q <= 2; q++)
                    if(r[3] == d[q])
                        c++;

                if(c != 1) break;
                else counter++;
            }

            else if(strike[j] == 3 && ball[j] == 0)
            {
                if(i == num[j]) counter++;
                else break;
            }

        }

        if(counter == n) ret[i] = true;
        else ret[i] = false;
    }
}

int main()
{
    int re = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d", &num[i], &strike[i],  &ball[i]);

    check();

    for(int i = 100; i <= 999; i++)
        if(ret[i] && i%10 != 0 && i%100/10 != 0 && i/100 != i%100/10 && i/100 != i%10 && i%100/10 != i%10) re++;

    printf("%d", re);

    return 0;
}
