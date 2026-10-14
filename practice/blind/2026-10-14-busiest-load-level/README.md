# Busiest Load Level

*2026-10-14 · C · pattern: Arrays & Hashing · re-solve*

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

I counted how often each level appears in a fixed array of 1001 slots, one for each possible reading from 0 to 1000. Then I scanned the counts from 0 upward and only replaced my answer when a count was strictly higher, so ties go to the smallest level without any extra logic. That makes it one pass over the readings plus one scan of the counts: time O(n + R) and space O(R), with R = 1001 and no dependence on n. An empty log (n == 0 or a NULL pointer) returns -1 up front.

## What I got wrong first

My first attempt looped to v <= 1001 over a 1001-element array, which read one slot past the end, and I also used `= {}` to initialize the array, which isn't standard C before C23. I fixed both, and my complexity claims were off too (I wrote O(n) space and O(n) time). The review still flags that I don't range-check readings, that Value is capitalized unlike my other locals, and that 1001 and 1000 are magic numbers I should replace with one named constant.

## Complexity

Time O(n + R) with R = 1001: one pass over the readings plus one scan of the counts. Space O(R): a fixed box[1001] array of ints, independent of n.

## Attempts

| # | Verdict | Score |
|---|---|---|
| 1 | partially correct | 6/10 |
| 2 | partially correct | 8/10 |
| 3 | accepted | 9/10 |

---
Solved from a blank file in a timed blind session, then reviewed and corrected before publishing.

Run: `clang -Wall -o solution solution.c && ./solution`
