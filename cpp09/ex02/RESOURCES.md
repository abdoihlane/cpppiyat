# PmergeMe (Ford-Johnson Merge-Insertion Sort) Resources

To prepare for your evaluation, you need to understand the theory behind the Ford-Johnson algorithm (Merge-Insertion Sort) and why Jacobsthal numbers are used.

## 1. The Ford-Johnson Algorithm Theory
The Ford-Johnson algorithm was designed to minimize the number of comparisons needed to sort a list. It combines elements of both Merge Sort and Insertion Sort.

### Key Steps:
1.  **Pairing:** Divide the unsorted list into pairs of two elements.
2.  **Sorting Pairs:** Compare the elements in each pair. Place the larger element on the "main chain" side and the smaller element on the "pend" (pending) side.
3.  **Recursive Sort:** Recursively sort the pairs based *only* on the larger elements (the main chain).
4.  **Insertion Phase:** Take the remaining smaller elements (the pend chain) and insert them into the main chain using binary search. The order of insertion is determined by Jacobsthal numbers to minimize the number of comparisons in the worst-case scenario.

## 2. Why Jacobsthal Numbers?
When inserting elements from the pend chain into the main chain, inserting them sequentially (1st, 2nd, 3rd) isn't optimal because the size of the search space grows in a way that maximizes binary search comparisons.

Jacobsthal numbers `(0, 1, 1, 3, 5, 11, 21, 43...)` provide the optimal insertion order. By inserting elements in the order of Jacobsthal sequence differences (e.g., insert the 3rd pend element, then the 2nd, then the 5th, then the 4th), you strategically limit the size of the main chain during each binary search, resulting in fewer comparisons.

## 3. Useful Links to Study
Here are some excellent resources to help you visualize and understand the algorithm before your evaluation:

*   **Wikipedia - Merge-insertion sort:**
    [https://en.wikipedia.org/wiki/Merge-insertion_sort](https://en.wikipedia.org/wiki/Merge-insertion_sort)
*   **A deeper dive into Ford-Johnson (Medium Article):**
    [https://medium.com/@mli42/merge-insertion-sort-in-c-42-cpp09-9136c1eeb6b4](https://medium.com/@mli42/merge-insertion-sort-in-c-42-cpp09-9136c1eeb6b4)
    *This article is widely used by 42 students specifically for the PmergeMe project.*
*   **Jacobsthal sequence explanation:**
    [https://en.wikipedia.org/wiki/Jacobsthal_number](https://en.wikipedia.org/wiki/Jacobsthal_number)
*   **Visualizing Sorting Algorithms:**
    [https://visualgo.net/en/sorting](https://visualgo.net/en/sorting) (Good for general sorting, though Ford-Johnson is a bit too specific, understanding general binary search and mergesort here helps).

Study these concepts well! Evaluators will often ask:
1. Why did you use Jacobsthal numbers?
2. How does `std::lower_bound` work? (It uses binary search).
3. Why did you choose `std::vector` and `std::deque` and what are their performance differences?
