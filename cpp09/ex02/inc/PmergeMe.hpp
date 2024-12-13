/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:18:49 by ampjimen          #+#    #+#             */
/*   Updated: 2024/12/13 19:26:54 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
    
    private:
        std::vector<int> _values_vec;
        std::deque<int> _values_deque;
        bool _alreadyPrinted;

        // Función para ordenar usando Ford-Johnson
        void fordJohnsonSort(std::vector<int> &container);
        void fordJohnsonSort(std::deque<int> &container);
        
        // Funciones de mergeInsert para std::vector
        void mergeInsert(std::vector<int>::iterator first, std::vector<int>::iterator last);
        // Funciones de mergeInsert para std::deque
        void mergeInsert(std::deque<int>::iterator first, std::deque<int>::iterator last);
        
        // Funciones auxiliares
        template <typename Container>
        void printContainer(const Container &container) const;

        template <typename Container>
        bool isSorted(const Container &container) const;

        //optimiza la inserción buscando la posición correcta
        template <typename Iterator>
        Iterator binaryInsert(Iterator first, Iterator last, typename Iterator::value_type value) {
        while (first != last) {
        Iterator mid = first + std::distance(first, last) / 2;
        if (*mid < value) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return first;
    }
    public:
        PmergeMe(const std::string &input);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        void init();
};

#endif
