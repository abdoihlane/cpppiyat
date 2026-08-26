#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.find_first_not_of("0123456789") != std::string::npos || arg.empty()) {
            throw std::invalid_argument("Error: Invalid positive integer sequence.");
        }
        int num = std::atoi(arg.c_str());
        if (num < 0) {
            throw std::invalid_argument("Error: Only positive integers allowed.");
        }
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

int PmergeMe::generateJacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return generateJacobsthal(n - 1) + 2 * generateJacobsthal(n - 2);
}

std::vector<int> PmergeMe::buildJacobsthalSequence(int size) {
    std::vector<int> jacobSeq;
    int index = 3; // start from Jacobsthal(3) = 3
    while (true) {
        int jacobNum = generateJacobsthal(index);
        if (jacobNum > size) {
            jacobSeq.push_back(jacobNum);
            break;
        }
        jacobSeq.push_back(jacobNum);
        index++;
    }
    return jacobSeq;
}

void PmergeMe::insertVector(std::vector<int>& mainChain, std::vector<int>& pend, std::vector<int>& oddElement) {
    if (pend.empty() && oddElement.empty()) return;

    std::vector<int> jacobSeq = buildJacobsthalSequence(pend.size());
    int lastInserted = 0;

    for (size_t i = 0; i < jacobSeq.size(); ++i) {
        int currentJacob = jacobSeq[i];
        int toInsert = std::min(currentJacob, static_cast<int>(pend.size()));

        for (int j = toInsert; j > lastInserted; --j) {
            int valToInsert = pend[j - 1];
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
            mainChain.insert(it, valToInsert);
        }
        lastInserted = toInsert;
    }

    if (!oddElement.empty()) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement[0]);
        mainChain.insert(it, oddElement[0]);
    }
}

void PmergeMe::sortVector(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    std::vector<int> mainChain;
    std::vector<int> pend;
    std::vector<int> oddElement;

    if (vec.size() % 2 != 0) {
        oddElement.push_back(vec.back());
        vec.pop_back();
    }

    for (size_t i = 0; i < vec.size(); i += 2) {
        if (vec[i] > vec[i+1]) {
            mainChain.push_back(vec[i]);
            pend.push_back(vec[i+1]);
        } else {
            mainChain.push_back(vec[i+1]);
            pend.push_back(vec[i]);
        }
    }

    sortVector(mainChain);
    
    // First element of pend is always smaller than the first element of mainChain
    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
        pend.erase(pend.begin());
    }

    insertVector(mainChain, pend, oddElement);
    vec = mainChain;
}


void PmergeMe::insertDeque(std::deque<int>& mainChain, std::deque<int>& pend, std::deque<int>& oddElement) {
    if (pend.empty() && oddElement.empty()) return;

    std::vector<int> jacobSeq = buildJacobsthalSequence(pend.size());
    int lastInserted = 0;

    for (size_t i = 0; i < jacobSeq.size(); ++i) {
        int currentJacob = jacobSeq[i];
        int toInsert = std::min(currentJacob, static_cast<int>(pend.size()));

        for (int j = toInsert; j > lastInserted; --j) {
            int valToInsert = pend[j - 1];
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
            mainChain.insert(it, valToInsert);
        }
        lastInserted = toInsert;
    }

    if (!oddElement.empty()) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement[0]);
        mainChain.insert(it, oddElement[0]);
    }
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1) return;

    std::deque<int> mainChain;
    std::deque<int> pend;
    std::deque<int> oddElement;

    if (deq.size() % 2 != 0) {
        oddElement.push_back(deq.back());
        deq.pop_back();
    }

    for (size_t i = 0; i < deq.size(); i += 2) {
        if (deq[i] > deq[i+1]) {
            mainChain.push_back(deq[i]);
            pend.push_back(deq[i+1]);
        } else {
            mainChain.push_back(deq[i+1]);
            pend.push_back(deq[i]);
        }
    }

    sortDeque(mainChain);

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
        pend.pop_front();
    }

    insertDeque(mainChain, pend, oddElement);
    deq = mainChain;
}

void PmergeMe::executeSort() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    // Time Vector
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sortVector(_vec);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    // Time Deque
    gettimeofday(&start, NULL);
    sortDeque(_deq);
    gettimeofday(&end, NULL);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
              
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " 
              << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}
