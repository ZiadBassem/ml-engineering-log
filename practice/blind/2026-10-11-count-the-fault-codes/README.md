# Count the Fault Codes

*2026-10-11 · C · pattern: Strings & parsing · easy*

## Problem

A compressor controller writes its status log as a single line of text. Each fault event in the log is marked by the letter `E` immediately followed by one or more digits (for example `E42`). Everything else in the line is just noise.

Write a function `int count_faults(const char *log)` that returns the number of fault events in the log.

A fault event is an uppercase `E` that is immediately followed by at least one digit `0`-`9`. An `E` that is not followed by a digit (end of string, a space, a letter, etc.) is not a fault event. Each `E` counts at most once, so `E123` is one fault event, not three.

**Input:** a null-terminated string `log` (possibly empty).

**Output:** an integer, the number of fault events.

| Input | Output |
|---|---|
| `"OK E42 OK E7 OK"` | `2` |
| `"ERROR E E5x END"` | `1` |
| `""` | `0` |

## Insight

I count a fault whenever I see an uppercase 'E' and the very next character is a digit '0'-'9'. Checking only the next character means E123 counts once, because the 1, 2 and 3 are never 'E' themselves, and a bare E followed by a space, letter, or the end of the string is skipped. Reading log[i+1] on the last character is safe because it just reads the '\0' terminator, which isn't a digit. I also cast to unsigned char before calling isdigit so a negative char can't cause undefined behavior.

## What I got wrong first

In my first attempt I called strlen before checking for NULL, so the guard did nothing and a NULL input would still crash, and the NULL branch returned 1 instead of 0. I also passed a plain char to isdigit without the unsigned char cast and left a TODO comment in. My final version fixes all of that, though it still makes two passes (strlen plus the loop) and stores a size_t in an int, so next time I'd loop with for (; *log; log++) and check log[1].

## Complexity

O(n) time (one strlen pass plus one loop pass, which is about 2n), O(1) extra space.

## Another approach: pointer walk (`solution_v2.c`)

[`solution_v2.c`](solution_v2.c) drops `strlen` and the index. It walks the pointer itself with `for (; *log; log++)` and checks `*log == 'E' && isdigit((unsigned char) log[1])`. The loop stops at the `'\0'` terminator, so the string is read in one pass instead of two, and there's no `size_t` result squeezed into an `int`. It is still O(n) time and O(1) extra space, and it passes the same 9 tests.

## Attempts

| # | Verdict | Score |
|---|---|---|
| 1 | partially correct | 8/10 |
| 2 | accepted | 9/10 |

## Similar problems

- LeetCode: Number of Segments in a String (#434)
- LeetCode: Valid Palindrome (#125)
- LeetCode: Length of Last Word (#58)

---
Solved from a blank file in a timed blind session, then reviewed and corrected before publishing.

Run: `clang -Wall -o solution solution.c && ./solution`

Run the pointer version: `clang -Wall -o solution_v2 solution_v2.c && ./solution_v2`
