#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* Return the number of fault events in log:
   an uppercase 'E' immediately followed by a digit '0'-'9'. */
int count_faults(const char *log)
{
    // initializing a count for errors, check NULL Crash
    int count = 0;
    if (log == NULL)
    {
        return 0;
    }
    // loop over the string for the ERROR Syntax
    int n = strlen(log);
    for (int i = 0; i < n; i++)
    {
        if (log[i] == 'E')
        {
            if (isdigit((unsigned char) log[i + 1]))
            {
                count++;
            }
        }
    }
    return count;
}

int main(void)
{
    struct
    {
        const char *input;
        int expected;
    } tests[] = {{"OK E42 OK E7 OK", 2},
                 {"ERROR E E5x END", 1},
                 {"", 0},
                 {"E1E2E3", 3},
                 {"E", 0},
                 {"e12 e5", 0},
                 {"E123456", 1},
                 {"all normal", 0},
                 {"temp 80 E9", 1}};
    int total = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int i = 0; i < total; i++)
    {
        int got = count_faults(tests[i].input);
        if (got == tests[i].expected)
        {
            printf("PASS %d\n", i + 1);
            passed++;
        }
        else
        {
            printf("FAIL %d\n", i + 1);
        }
    }

    printf("%d/%d passed\n", passed, total);
    return passed == total ? 0 : 1;
}
