#include <stdio.h>

/* Return the most frequent value in readings (ties -> smallest value).
   Return -1 if n == 0. */
int most_common_reading(const int *readings, int n)
{
    if (readings == NULL || n == 0)
    {
        return -1;
    }
    int box[1001] = {0};
    for (int i = 0; i < n; i++)
    {
        int Value = readings[i];
        box[Value] = box[Value] + 1;
    }
    int highest = 0;
    int lvl = 0;
    for (int v = 0; v <= 1000; v++)
    {
        if (box[v] > highest)
        {
            highest = box[v];
            lvl = v;
        }
    }
    return lvl;
}

static int passed = 0;
static int total = 0;

static void check(int id, const int *a, int n, int expected)
{
    total++;
    if (most_common_reading(a, n) == expected)
    {
        passed++;
        printf("PASS %d\n", id);
    }
    else
    {
        printf("FAIL %d\n", id);
    }
}

int main(void)
{
    int t1[] = {5, 3, 5, 3, 7};
    int t2[] = {10};
    int t4[] = {0, 0, 1000, 1000, 1000};
    int t5[] = {1, 2, 3, 4};
    int t6[] = {7, 7, 7, 7};
    int t7[] = {900, 12, 900, 12, 12, 900, 5};
    int t8[] = {1000, 0};

    check(1, t1, 5, 3);
    check(2, t2, 1, 10);
    check(3, NULL, 0, -1);
    check(4, t4, 5, 1000);
    check(5, t5, 4, 1);
    check(6, t6, 4, 7);
    check(7, t7, 7, 12);
    check(8, t8, 2, 0);

    printf("%d/%d passed\n", passed, total);
    return 0;
}
