# Busiest Load Level

*2026-10-08 · C · pattern: Arrays & Hashing · easy*

## Problem

A grid monitor logs integer load levels, one reading per minute. Each level is an integer from 0 to 1000. Implement `int most_common_reading(const int *readings, int n)`, which returns the load level that appears most often in the log.

- If several levels share the highest count, return the **smallest** of them.
- If the log is empty (`n == 0`), return `-1`.

**Input:** a pointer to an array `readings` of `n` integers, and `n`.

**Output:** a single integer, the most frequent level (or `-1` for an empty log).

| Input | Output |
|---|---|
| `readings = [5, 3, 5, 3, 7], n = 5` | `3` |
| `readings = [0, 0, 1000, 1000, 1000], n = 5` | `1000` |
| `readings = [], n = 0` | `-1` |

## Insight

Since levels are integers from 0 to 1000, I can use a fixed 1001-int counting array and tally each reading in one pass. Then I scan levels 0 through 1000 in ascending order and only update the best when a count is strictly greater. That ascending scan with strict > gives the smallest-level tie-break without any extra logic. It runs in O(n + R) time and O(R) space with R = 1001, and an empty log returns -1 up front.

## What I got wrong first

My first attempts didn't implement the counting array: #1 was the untouched starter, and #2 didn't compile because of cs50.h, get_int, and an out-of-bounds readings[n]. In #3 I had the comparison backwards (best_count > count[v]), so the best level always stayed 0. I also left a stray printf in the n == 0 branch and misstated the complexity as O(n) time and O(1) or O(n) space, and I needed a few rounds to fix those.

## Complexity

Time O(n + R) with R=1001: one pass over the input plus a fixed scan of 1001 levels. Space O(R): a fixed 1001-int array on the stack, independent of n.

## Attempts

| # | Verdict | Score |
|---|---|---|
| 1 | incorrect | 0/10 |
| 2 | doesn't compile | 1/10 |
| 3 | incorrect | 3/10 |
| 4 | partially correct | 8/10 |
| 5 | partially correct | 8/10 |
| 6 | accepted | 10/10 |
| 7 | accepted | 10/10 |

## Similar problems

- LeetCode: Contains Duplicate (#217)
- LeetCode: Valid Anagram (#242)
- LeetCode: Majority Element (#169)

---
Solved from a blank file in a timed blind session, then reviewed and corrected before publishing.

Run: `clang -Wall -o solution solution.c && ./solution`
