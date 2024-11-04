/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:15 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/04 19:19:28 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <iostream>

Span::Span(unsigned int N) : maxSize(N)
{
    numbers.reserve(N);
}

Span::Span(Span const &other)
{
    *this = other;
}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

/////////////////////////////////////////

const std::vector<int>& Span::getNumbers() const {
    return numbers;
}

// Añadir un solo número
void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::runtime_error("Cannot add more numbers: maximum size reached.");
    }
    numbers.push_back(number);
}


// Calcular el span más corto
int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate shortest span.");
    }

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    
    int shortest = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
        int span = sortedNumbers[i + 1] - sortedNumbers[i];
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

// Calcular el span más largo
int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate longest span.");
    }

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}
