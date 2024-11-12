/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:18:49 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/12 21:54:18 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <ctime>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<unsigned int> _values_vec;
    std::deque<unsigned int> _values_deque;
    bool _alreadyPrinted;

    template <typename Container>
    void fordJohnsonSort(Container &container);
    template <typename Container>
    void printContainer(const Container &container);
    template <typename Container>
    bool isSorted(const Container &container);

    PmergeMe();

public:
    PmergeMe(const std::string &input);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    
    void init();
};

#endif 
