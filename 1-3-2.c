#include <stdio.h>

typedef struct r
{
    int i;
    int len;
    int sum;
} r;

r foo(int *a, int len)
{
    int i, j, max, sum = -999;
    r s = {0, 0, 0};
    for (i = 0; i < len; ++i)
    {
        sum = 0;
        for (j = i; j < len; ++j)
        {
            sum += *(a + j);
            if (sum > max)
            {
                max = sum;
                s.i = i;
                s.len = j - i + 1;
                s.sum = sum;
            }
        }
    }
    return s;
}

int main()
{
    int a[] = {4, 9, 0, 2, 3, -1, -77, 88, -4};
    r s = foo((int*)&a, 9);
    printf("{i: %i, len: %i, sum: %i}", s.i, s.len, s.sum);
    return 0;
}