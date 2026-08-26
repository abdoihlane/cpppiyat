# RPN Code Explanation

This document explains the core logic of the `RPN.cpp` code so you can confidently answer questions during evaluation.

## 1. The Core Loop (Token Parsing)

```cpp
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
```
**Explanation:** `std::stringstream` is used to split the input string by whitespace. This means if you input `"8 9 * 9 - 9 - 9 - 4 1 + +"`, the `while` loop extracts `"8"`, `"9"`, `"*"`, etc., one at a time into the variable `token`. This is cleaner than writing manual string-splitting functions.

## 2. Pushing Numbers

```cpp
        if (isOperator(token)) {
            performOperation(token);
        } else {
            // ... (validation checks here)
            _stack.push(std::atoi(token.c_str()));
        }
```
**Explanation:** If the token is not an operator (`+`, `-`, `*`, `/`), we assume it's a number. We first validate it (ensure it's all digits) and then convert it to an integer using `std::atoi`. We then push it onto our `std::stack`.

## 3. Performing the Operation

```cpp
    if (_stack.size() < 2) {
        throw std::runtime_error("Error");
    }

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();
```
**Explanation:** Whenever we hit an operator, we need two operands. 
1. We check if we have at least 2 numbers in the stack. If not, the user inputted something invalid like `"5 +"`.
2. **Order matters!** We pop the top number into `b`, and the next number into `a`. Because a stack is LIFO, the top number (`b`) was the *second* number written in the expression. So for `"5 2 -"`, `b` will be `2`, and `a` will be `5`. The operation must be `a - b`, not `b - a`.

```cpp
    if (op == "+") _stack.push(a + b);
    else if (op == "-") _stack.push(a - b);
    else if (op == "*") _stack.push(a * b);
    else if (op == "/") {
        if (b == 0) throw std::runtime_error("Error");
        _stack.push(a / b);
    }
```
**Explanation:** Finally, we perform the math based on the operator and immediately push the result back onto the stack. We also guard against division by zero.

## 4. Final Validation

```cpp
    if (_stack.size() != 1) {
        throw std::runtime_error("Error");
    }
    std::cout << _stack.top() << std::endl;
```
**Explanation:** When the `while` loop finishes, a valid RPN expression should leave exactly **one** number on the stack (the final answer). If the stack is empty, or has 2+ numbers (e.g., input was `"5 5 5 +"`), it's an error. Otherwise, we print the answer.
