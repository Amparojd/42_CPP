/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:38 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/03 20:50:05 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../inc/Span.hpp"

int main() {
    Span sp = Span(10); // Cambiar a 10 para permitir más números

    // Agregar números individuales
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    // Imprimir números actuales
    std::cout << "Números en Span: ";
    const std::vector<int>& numbers = sp.getNumbers();
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Probar las funciones de span
    try {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Agregar múltiples números usando addNumbers
    std::vector<int> extraNumbers;
    extraNumbers.push_back(12);
    extraNumbers.push_back(5);
    extraNumbers.push_back(8);

    try {
        sp.addNumbers(extraNumbers.begin(), extraNumbers.end());
    } catch (const std::exception &e) {
        std::cerr << "Exception when adding multiple numbers: " << e.what() << std::endl;
    }

    // Imprimir números después de añadir más
    std::cout << "Números en Span después de agregar más: ";
    numbers = sp.getNumbers(); // Volver a obtener la referencia después de agregar más
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Probar nuevamente las funciones de span
    try {
        std::cout << "Shortest span después de agregar más: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span después de agregar más: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

