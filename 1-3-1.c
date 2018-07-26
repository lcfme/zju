#include <stdio.h>

typedef struct result
{
    int i;
    int len;
    int sum;
} result;

result foo(int *a, int len)
{
    int i, j, sum, max = -999;
    result s = {0, 0, 0};
    for (i = 0; i < len; ++i)
    {
        for (j = i; j < len; ++j)
        {
            sum = 0;
            for(int k = i; k <= j; ++k)
            {
                sum += *(a + k);
            }
            if (sum > max) {
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
    int a[] = {4, 2, -1, -9};
    result s = foo((int*)&a, 4);
    printf("{i: %i, len: %i, sum: %i}\n", s.i, s.len, s.sum);
    return 0;
}
