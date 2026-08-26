#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sys/time.h>
#include <iomanip>
#include <stdlib.h>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    // Helper functions for vector
    void sortVector(std::vector<int>& vec);
    void insertVector(std::vector<int>& mainChain, std::vector<int>& pend, std::vector<int>& oddElement);

    // Helper functions for deque
    void sortDeque(std::deque<int>& deq);
    void insertDeque(std::deque<int>& mainChain, std::deque<int>& pend, std::deque<int>& oddElement);

    // Common utils
    int generateJacobsthal(int n);
    std::vector<int> buildJacobsthalSequence(int size);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseInput(int argc, char **argv);
    void executeSort();
};

#endif
