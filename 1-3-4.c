#include <stdio.h>

typedef struct o
{
    int i;
    int len;
    int sum;
} o;

o foo(int a[], int len)
{
    int max = -999, sum = 0, j = 0;
    o s = {0, 0, 0};
    for (int i = 0; i < len; ++i)
    {
        sum += a[i];
        if (sum > max)
        {
            s.i = i;
            s.len = i - j + 1;
            s.sum = sum;
            max = sum;
        }
        else if (sum < 0)
        {
            sum = 0;
            j = i;
        }
    }
    return s;
}

int main()
{
    int a[] = {4, 9, 0, 2, 3, -1, -77, 88, -4};
    o s = foo((int *)&a, 9);
    printf("{i: %i, len: %i, sum: %i}", s.i, s.len, s.sum);
    return 0;
}