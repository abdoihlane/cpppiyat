# RPN (Reverse Polish Notation) Resources

To prepare for your evaluation on `ex01`, you need to understand what Reverse Polish Notation is and why the `std::stack` is the perfect container for evaluating it.

## 1. What is Reverse Polish Notation?
Also known as postfix notation, RPN is a mathematical notation where every operator follows all of its operands. It eliminates the need for parentheses that are required by infix notation.
*   **Infix (Normal):** `(3 + 4) * 5`
*   **Postfix (RPN):** `3 4 + 5 *`

In RPN, as soon as you see an operator, you immediately apply it to the previous two numbers.

## 2. Why use a Stack?
A stack is a LIFO (Last-In, First-Out) data structure. When processing an RPN expression from left to right:
1.  When you encounter a number, you **push** it onto the stack.
2.  When you encounter an operator, you **pop** the top two numbers from the stack, perform the operation, and **push** the result back onto the stack.
3.  When you finish processing the entire expression, the final answer will be the only item remaining on the stack.

`std::stack` in C++ provides precisely the operations we need (`push()`, `pop()`, `top()`, `size()`) without allowing arbitrary access to the middle of the container, which enforces the strict LIFO logic required by the algorithm.

## 3. Useful Links to Study
Here are some resources to help you visualize and understand RPN before your evaluation:

*   **Wikipedia - Reverse Polish notation:**
    [https://en.wikipedia.org/wiki/Reverse_Polish_notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
*   **Computerphile Video on RPN (Highly Recommended):**
    [https://www.youtube.com/watch?v=7ha78yWRDlE](https://www.youtube.com/watch?v=7ha78yWRDlE)
*   **Evaluating RPN Expressions Tutorial:**
    [https://www.geeksforgeeks.org/evaluate-the-value-of-an-postfix-expression/](https://www.geeksforgeeks.org/evaluate-the-value-of-an-postfix-expression/)

Study these concepts well! Evaluators will often ask:
1. Why did you choose `std::stack` for this problem?
2. What happens if there are too many operators? (The stack runs out of numbers, causing an error).
3. What happens if there are too many numbers? (The stack will have more than 1 item left at the end, causing an error).
4. How do you handle division by zero?
