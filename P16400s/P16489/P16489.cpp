#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
   // int q,w,e;
    //scanf("%d%d%d", &q, &w, &e);
   // printf("%.13lf\n", sqrt((q+w+e)*(w+e-q)*(q+e-w)*(w+e-q))/4);
    double S = sqrt(4*a*a*b*b-(a*a+b*b-c*c)*(a*a+b*b-c*c))/4;
    double R = a*b*c/(4*S);
    double r = 2*S/(a+b+c);
    double d = sqrt(max(R*(R-2*r), (double)0));
    if(a==b && b==c) d = 0;
    double k = sqrt((R*R-a*a/4)) + sqrt((R*R-b*b/4)) + sqrt((R*R-c*c/4));
  //  double test = sqrt((a+b+c)*(b+c-a)*(a+c-b)*(b+c-a))/4;
    //printf("%.13lf\n", test);
    printf("%.13lf\n%.13lf\n%.13lf\n%.13lf\n%.13lf\n", S, R, r, d, k);

    return 0;
}
