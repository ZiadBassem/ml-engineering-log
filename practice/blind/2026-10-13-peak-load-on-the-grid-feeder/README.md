# Peak Load on the Grid Feeder

*2026-10-13 · C · pattern: Linked List · easy*

## Problem

A grid monitoring system stores hourly feeder load readings (in kW) in a singly linked list, one node per hour, in time order. Write a function that returns the **highest** reading in the list.

Implement `int max_load(node *head)` where `node` is defined as:

```c
typedef struct node {
    int load;
    struct node *next;
} node;
```

**Input:** `head`, a pointer to the first node of the list (or `NULL` if the list is empty).

**Output:** the largest `load` value in the list. If the list is empty, return `-1`.

| Input | Output |
|---|---|
| `head -> 120 -> 340 -> 275 -> NULL` | `340` |
| `head -> 50 -> NULL` | `50` |
| `head = NULL` | `-1` |

## Insight

I handled the empty list first by returning -1 when head is NULL, so nothing gets dereferenced after that. Then I started highest at head->load instead of an arbitrary number like 0, which keeps it correct for any real reading. After that it's one pass with cursor, updating highest whenever a node's load is bigger, and looping on cursor != NULL so the last node gets checked too. That's O(n) time and O(1) extra space.

## What I got wrong first

My first attempt didn't compile because a second copy of the whole program got pasted inside check(), and the logic had several bugs. I read head->next before checking head for NULL, returned -1 for a one-node list, looped on cursor->next != NULL so the last node was never examined, and used an unsigned int for highest. I also left a no-op line, cursor->next = head->next. The final version fixes all of these, though the stale TODO comment still needs deleting.

## Complexity

O(n) time, O(1) extra space: one pass over the list with two local variables (highest, cursor).

## Attempts

| # | Verdict | Score |
|---|---|---|
| 1 | doesn't compile | 1/10 |
| 2 | accepted | 9/10 |

## Similar problems

- LeetCode: Reverse Linked List (#206)
- LeetCode: Middle of the Linked List (#876)
- LeetCode: Linked List Cycle (#141)

---
Solved from a blank file in a timed blind session, then reviewed and corrected before publishing.

Run: `clang -Wall -o solution solution.c && ./solution`
