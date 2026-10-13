#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int load;
    struct node *next;
} node;

// Return the largest load in the list, or -1 if the list is empty.
int max_load(node *head)
{
    // TODO: implement
    if (head == NULL)
    {
        return -1;
    }
    int highest = head->load;
    node *cursor = head;
    while (cursor != NULL)
    {
        if (cursor->load > highest)
        {
            highest = cursor->load;
        }
        cursor = cursor->next;
    }
    return highest;
}

// Helper: build a list from an array (n may be 0). Returns head.
static node *build(const int *a, int n)
{
    node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        node *m = malloc(sizeof(node));
        if (m == NULL)
        {
            return head;
        }
        m->load = a[i];
        m->next = head;
        head = m;
    }
    return head;
}

static void free_list(node *head)
{
    while (head != NULL)
    {
        node *next = head->next;
        free(head);
        head = next;
    }
}

static int check(int n, const int *a, int len, int expected)
{
    node *head = build(a, len);
    int got = max_load(head);
    free_list(head);
    if (got == expected)
    {
        printf("PASS %d\n", n);
        return 1;
    }
    printf("FAIL %d\n", n);
    return 0;
}

int main(void)
{
    int passed = 0;
    int total = 7;

    int t1[] = {120, 340, 275};
    int t2[] = {50};
    int t3[] = {900, 10, 20, 30};
    int t4[] = {1, 2, 3, 4, 5};
    int t5[] = {0, 0, 0};
    int t6[] = {100000, 99999};
    int t7[] = {7, 7, 8, 7};

    passed += check(1, t1, 3, 340);
    passed += check(2, t2, 1, 50);
    passed += check(3, t3, 4, 900);
    passed += check(4, t4, 5, 5);
    passed += check(5, t5, 3, 0);
    passed += check(6, t6, 2, 100000);
    passed += check(7, NULL, 0, -1);
    (void) t7;

    printf("%d/%d passed\n", passed, total);
    return 0;
}
