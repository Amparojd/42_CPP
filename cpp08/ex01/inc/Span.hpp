/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:34:42 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/03 20:46:31 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm> 
#include <ostream>

class Span {

private:
    std::vector<int> numbers;
    unsigned int maxSize;
    
public:
    Span(unsigned int N);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();
    
    void    addNumber(int number);
    template <typename Iterator>
    void    addNumbers(Iterator begin, Iterator end);
    int     shortestSpan() const;
    int     longestSpan() const;
    
    // Método para obtener los números
    const std::vector<int>& getNumbers() const;
};

#endif
