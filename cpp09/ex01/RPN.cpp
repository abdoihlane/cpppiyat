#include "RPN.hpp"
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

void RPN::performOperation(const std::string& op) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error"); 
    }

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    if (op == "+") _stack.push(a + b);
    else if (op == "-") _stack.push(a - b);
    else if (op == "*") _stack.push(a * b);
    else if (op == "/") {
        if (b == 0) throw std::runtime_error("Error"); 
        _stack.push(a / b);
    }
}

void RPN::calculate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isOperator(token)) {
            performOperation(token);
        } else {
            if (token.length() > 1 && token.find_first_not_of("0123456789") != std::string::npos) {
                if (!(token[0] == '-' && token.length() > 1 && token.substr(1).find_first_not_of("0123456789") == std::string::npos)) {
                     throw std::runtime_error("Error");
                }
            } else if (token.length() == 1 && !std::isdigit(token[0]) && !isOperator(token)) {
                 throw std::runtime_error("Error");
            }
            
            _stack.push(std::atoi(token.c_str()));
        }
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Error");
    }

    std::cout << _stack.top() << std::endl;
}
