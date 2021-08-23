#include <cstdio>

int main()
{
    int x, y, w, h, v;
    scanf("%d%d%d%d", &x, &y, &w, &h);
    printf("%d", (x <= y ? x : y) < (w-x <= h-y ? w-x : h-y) ? (x <= y ? x : y) : (w-x <= h-y ? w-x : h-y));
    return 0;
}
