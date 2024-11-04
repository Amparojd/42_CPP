/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:38 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/04 19:24:35 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Span.hpp"
#include <vector>

void printVector(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void runTests() {

    std::cout << "-=====TEST 0 - EXCEPTION HANDLING ONE NUMBER ==========" << std::endl;
    Span sp0(1);
    try{
        sp0.addNumber(1);
        std::cout << " - Shortest span: " << sp0.shortestSpan() << std::endl;
        std::cout << " - Longest span: " << sp0.longestSpan() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "-=====TEST 1 - ADDING NUMBERS INDIVIDUALLY ==========" << std::endl;
    Span sp1(5);
    sp1.addNumber(1);
    sp1.addNumber(3);
    sp1.addNumber(6);
    sp1.addNumber(9);
    sp1.addNumber(7);
    std::cout << "Numbers in Span : ";
    printVector(sp1.getNumbers());
    std::cout << " - Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << " - Longest span: " << sp1.longestSpan() << std::endl;
    std::cout << std::endl;
    
    std::cout << "-=====TEST 2 - ADDING NUMBERS USING ADDNUMBERS ==========" << std::endl;
    Span sp2(5);
    std::vector<int> numbersToAdd;
    numbersToAdd.push_back(7);
    numbersToAdd.push_back(8);
    numbersToAdd.push_back(9);
    numbersToAdd.push_back(11);
    numbersToAdd.push_back(17);
    sp2.addNumbers(numbersToAdd.begin(), numbersToAdd.end());
    std::cout << "Numbers in Span: ";
    printVector(sp2.getNumbers());
    std::cout << " - Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << " - Longest span: " << sp2.longestSpan() << std::endl;
    std::cout << std::endl;

    
    std::cout << "-=====TEST 3 - COMBINING ADDING NUMBERS AND CALCULATING SPANS ==========" << std::endl;
    Span sp3(6);
    std::vector<int> additionalNumbers;
    additionalNumbers.push_back(10);
    additionalNumbers.push_back(15);
    additionalNumbers.push_back(20);
    additionalNumbers.push_back(30);
    additionalNumbers.push_back(5);
    additionalNumbers.push_back(1);
    sp3.addNumbers(additionalNumbers.begin(), additionalNumbers.end());
    std::cout << "Numbers in Span: ";
    printVector(sp3.getNumbers());
    std::cout << " - Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << " - Longest span: " << sp3.longestSpan() << std::endl;
    std::cout << std::endl;

    
    std::cout << "-=====TEST 4 - EXCEPTION HANDLING ==========" << std::endl;
    Span sp4(3);
    sp4.addNumber(1);
    sp4.addNumber(2);
    sp4.addNumber(3);
    try {
        sp4.addNumber(4);  // Esto debe lanzar una excepción
    } catch (const std::runtime_error &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-=====TEST 5 - USING ITERATORS ==========" << std::endl;
    Span sp5(4);
    std::vector<int> numbers;
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);
    
    // Agregar números al Span usando iteradores
    sp5.addNumbers(numbers.begin(), numbers.end());

    // Ahora, imprime los números que se han añadido
    std::cout << "Numbers in Span: ";
    printVector(sp5.getNumbers());  // Aquí llamar a getNumbers() para mostrar los números

    std::cout << " - Shortest span: " << sp5.shortestSpan() << std::endl;
    std::cout << " - Longest span: " << sp5.longestSpan() << std::endl;
    std::cout << std::endl;
}

int main() {
    runTests();
    return 0;
}
