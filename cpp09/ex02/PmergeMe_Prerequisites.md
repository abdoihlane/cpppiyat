# Before You Read the PmergeMe Explanation

This is a prep sheet for the concepts the `PmergeMe.cpp` explanation assumes you
already know. Read this first, then the code walkthrough will make a lot more sense.

---

## 1. What This Code Actually Implements

`PmergeMe` is a classic 42 School project. The algorithm being implemented is the
**Ford-Johnson algorithm**, also called **merge-insertion sort**. It's known for
using close to the theoretical minimum number of comparisons needed to sort a
sequence — which is why the project usually asks you to also implement
`std::vector` and `std::deque` versions and compare their timing.

High-level idea, in plain English before you see any code:

1. Split the input into pairs and sort each pair internally (small, large).
2. Take the larger element of each pair, and recursively sort *that* sub-sequence
   (this becomes the "main chain").
3. Now you have a bunch of "leftover" smaller elements (the "pend" list) that
   still need to be inserted into the sorted main chain.
4. Insert them one at a time using binary search — but *not* in the naive order.
   The clever part is the **order** in which you insert them, which is where
   Jacobsthal numbers come in (see below). This ordering minimizes the number of
   comparisons `lower_bound` needs to do.

If you only remember one thing: **pairing + recursive sort of the larger halves +
a cleverly-ordered binary-search insertion of the smaller halves.**

---

## 2. Jacobsthal Numbers — what and why

The Jacobsthal sequence is: `0, 1, 1, 3, 5, 11, 21, 43, 85, ...`

Formula: `J(n) = J(n-1) + 2*J(n-2)`, with `J(0)=0`, `J(1)=1`.

**Why it matters here:** when inserting the "pend" elements back into the sorted
main chain, the *order* you insert them in changes how large a range
`lower_bound` has to search. Sorting theory (specifically, this algorithm's
proof) shows that inserting elements in **groups whose sizes follow the
Jacobsthal sequence, and within each group inserting backwards**, keeps every
individual binary search as small as possible. That's the whole reason this
sequence shows up instead of just inserting pend[0], pend[1], pend[2]... in
order.

You don't need to derive this yourself — just know *that* it's the
comparison-minimizing insertion order, and that's why it's there.

---

## 3. Tools/Concepts You Should Already Be Comfortable With

- **Recursion**: `generateJacobsthal` and `sortVector` both call themselves.
  You should be comfortable tracing a recursive call down to its base case.
- **`std::lower_bound`**: returns an iterator to the first element *not less
  than* a given value in a sorted range — i.e., it's a binary search. This is
  how the algorithm gets its efficiency; without it, insertion would be O(n)
  per element instead of O(log n) for the *search* (insertion itself is still
  O(n) for `vector` because of shifting — see point below).
- **`vector::insert` cost**: inserting into the middle of a `std::vector`
  requires shifting every element after the insertion point. This is O(n) per
  insert, even though *finding* the spot via `lower_bound` is O(log n).
  Understanding this distinction matters if you're asked to justify
  vector vs. deque performance.
- **`std::deque` internals**: a deque is implemented as a sequence of fixed-size
  chunks (not one contiguous block like a vector). This is why push_front/
  push_back are cheap on a deque, but random access and cache locality are
  worse than a vector's.
- **Big-O basics**: know the difference between search complexity and
  insertion/shift complexity, since evaluators often probe exactly this.

---

## 4. Vocabulary Quick Reference

| Term | Meaning in this code |
|---|---|
| `mainChain` | The sequence being recursively sorted (the "large" elements of each pair) |
| `pend` | The leftover "small" elements waiting to be inserted |
| `jacobSeq` | Precomputed Jacobsthal numbers used to decide insertion batch sizes |
| `lastInserted` | Tracks how far into `pend` we've already inserted |
| `toInsert` | The upper bound (clamped to `pend.size()`) of the current insertion batch |

---

## 5. Resources to Check Later

- **Wikipedia – Merge-insertion sort (Ford–Johnson algorithm)**
  https://en.wikipedia.org/wiki/Merge-insertion_sort
  Good for the formal proof sketch and comparison-count optimality claims.

- **Wikipedia – Jacobsthal number**
  https://en.wikipedia.org/wiki/Jacobsthal_number
  Background on the sequence itself, independent of sorting.

- **cppreference – std::lower_bound**
  https://en.cppreference.com/w/cpp/algorithm/lower_bound

- **cppreference – std::vector**
  https://en.cppreference.com/w/cpp/container/vector

- **cppreference – std::deque**
  https://en.cppreference.com/w/cpp/container/deque

- **42 School subject PDF for PmergeMe** (search your intranet/cluster resources
  or peer repos — the exact wording of constraints, like which containers are
  mandatory, comes from your specific subject sheet, so check that directly
  rather than relying on secondhand explanations).

---

## 6. Suggested Reading Order

1. This file (done!)
2. `generateJacobsthal` — trivial recursion, confirms the formula
3. The pairing loop in `sortVector` — straightforward
4. `sortVector(mainChain)` recursive call — trust the recursion, don't
   re-trace it by hand
5. The `pend[0]` special-case insert — makes sense once you know mainChain[0]
   was its pair partner
6. `insertVector` — read this *last* and *slowly*; it's genuinely the hardest
   part, and re-reading section 2 above while tracing through a small example
   (try n=5 or 6 by hand) helps a lot.
