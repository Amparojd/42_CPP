/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:19:10 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/12 21:55:28 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <sstream>

PmergeMe::PmergeMe(const std::string &input) {
    std::stringstream ss(input);
    int num;
    
    while (ss >> num) {
        if (num <= 0) {  // Verificar si el número es negativo o cero
            throw std::invalid_argument("Error: Negative or zero values are not allowed");
        }
        _values_vec.push_back(num);
        _values_deque.push_back(num);
    }
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _values_vec(other._values_vec),
      _values_deque(other._values_deque),
      _alreadyPrinted(other._alreadyPrinted) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _values_vec = other._values_vec;
        _values_deque = other._values_deque;
        _alreadyPrinted = other._alreadyPrinted;
    }
    return *this;
}

////////////////////////////////////////////////////////////////////////


template <typename Container>
void PmergeMe::fordJohnsonSort(Container &container) {
    if (container.size() < 2) return;

    Container temp;
    typename Container::iterator it = container.begin();
    while (it != container.end()) {
        typename Container::value_type first = *it;
        ++it;
        if (it == container.end()) {
            temp.push_back(first);
            break;
        }
        typename Container::value_type second = *it;
        ++it;

        if (first < second) {
            temp.push_back(first);
            temp.push_back(second);
        } else {
            temp.push_back(second);
            temp.push_back(first);
        }
    }

    Container sortedMedians;
    sortedMedians.push_back(temp[1]);
    for (size_t i = 3; i < temp.size(); i += 2) {
        typename Container::iterator pos = std::lower_bound(
            sortedMedians.begin(), sortedMedians.end(), temp[i]);
        sortedMedians.insert(pos, temp[i]);
    }

    for (size_t i = 0; i < temp.size(); i += 2) {
        typename Container::iterator pos = std::lower_bound(
            sortedMedians.begin(), sortedMedians.end(), temp[i]);
        sortedMedians.insert(pos, temp[i]);
    }

    container = sortedMedians;
}

template <typename Container>
void PmergeMe::printContainer(const Container &container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
bool PmergeMe::isSorted(const Container &container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end() - 1; ++it) {
        if (*it > *(it + 1)) return false;
    }
    return true;
}

void PmergeMe::init() {
    try {
        std::cout << "Before: ";
        printContainer(_values_vec);
        clock_t start = clock();
        fordJohnsonSort(_values_vec);
        clock_t end = clock();
        std::cout << "After: ";
        printContainer(_values_vec);
        std::cout << "Time to process with std::vector: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;

        start = clock();
        fordJohnsonSort(_values_deque);
        end = clock();
        std::cout << "Time to process with std::deque: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

