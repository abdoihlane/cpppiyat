# PmergeMe Code Explanation

This document explains the most complex and important parts of the `PmergeMe.cpp` code so you can confidently answer questions during evaluation.

## 1. Generating Jacobsthal Numbers

```cpp
int PmergeMe::generateJacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return generateJacobsthal(n - 1) + 2 * generateJacobsthal(n - 2);
}
```
**Explanation:** This is a simple recursive function that generates the `n`-th Jacobsthal number. The formula is `J(n) = J(n-1) + 2 * J(n-2)`.

## 2. The Sorting Logic (sortVector)

```cpp
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (vec[i] > vec[i+1]) {
            mainChain.push_back(vec[i]);
            pend.push_back(vec[i+1]);
        } else {
            mainChain.push_back(vec[i+1]);
            pend.push_back(vec[i]);
        }
    }
```
**Explanation:** This is the **Pairing Phase**. We iterate through the vector in steps of 2. For each pair, we compare them. The larger number goes into `mainChain` (the sequence we will recursively sort), and the smaller number goes into `pend` (the sequence we will insert later).

```cpp
    sortVector(mainChain);
```
**Explanation:** The **Recursive Sort Phase**. We call the same function to sort our `mainChain`. When this function returns, `mainChain` is perfectly sorted.

```cpp
    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
        pend.erase(pend.begin());
    }
```
**Explanation:** Since `mainChain` was sorted, we know that the element originally paired with `mainChain[0]` (which is `pend[0]`) is guaranteed to be smaller than `mainChain[0]`. Thus, we don't even need to search for its position; it simply goes at the very beginning of the `mainChain`.

## 3. The Insertion Logic (insertVector)

This is the hardest part of the code to understand.

```cpp
    std::vector<int> jacobSeq = buildJacobsthalSequence(pend.size());
    int lastInserted = 0;
```
**Explanation:** We generate a list of Jacobsthal numbers up to the size of our `pend` list. `lastInserted` keeps track of how many elements from `pend` we have successfully inserted into `mainChain`.

```cpp
    for (size_t i = 0; i < jacobSeq.size(); ++i) {
        int currentJacob = jacobSeq[i];
        int toInsert = std::min(currentJacob, static_cast<int>(pend.size()));
```
**Explanation:** We loop through the Jacobsthal sequence. The `currentJacob` tells us *up to what index* in the `pend` array we should process in this batch. If the Jacobsthal number is larger than our pend size, we just clamp it to `pend.size()`.

```cpp
        for (int j = toInsert; j > lastInserted; --j) {
            int valToInsert = pend[j - 1];
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
            mainChain.insert(it, valToInsert);
        }
```
**Explanation:** **This is the core of Ford-Johnson's efficiency.** Instead of inserting `pend` elements forwards (1st, 2nd, 3rd), we insert them **backwards** starting from the current Jacobsthal index down to the last inserted index. 
For example, if Jacobsthal tells us to process up to index 3, and we previously processed up to index 1, we insert `pend[2]` then `pend[1]`.
*   `std::lower_bound` performs a **binary search** on the `mainChain` to find the exact iterator position where `valToInsert` should go to keep the list sorted.
*   `mainChain.insert` then places it there.

## Why std::vector vs std::deque?
During the evaluation, you might be asked why one is faster. 
*   `std::vector` has contiguous memory, which makes iterating and accessing elements very fast due to CPU cache locality. However, inserting in the middle is slow because elements must be shifted.
*   `std::deque` (double-ended queue) is a collection of contiguous chunks. Inserting in the middle can sometimes be slightly faster than vector for huge datasets, but its cache locality is worse. For this algorithm, `std::vector` is typically faster because of how heavily we use binary search and iteration, but `std::deque` serves as our required secondary container.
