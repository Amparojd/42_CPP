/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:45:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/28 18:48:30 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/iter.hpp"

//Función que incrementa en 1 cada elemento del array
void increment(int &value)
{
    value += 1;
}

//Función que convierte a mayúsculas cada elemento del array
void toUpperCase(char &c)
{
    if(c >= 'a' && c <= 'z')
        c -= ('a' - 'A');
}

int main() {
    // Prueba con un array de enteros
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, print<int>);
    std::cout << "\n";

    iter(intArray, intArrayLength, increment);

    std::cout << "Modified int array (incremented): ";
    iter(intArray, intArrayLength, print<int>);
    std::cout << "\n";

    // Prueba con un array de caracteres
    char charArray[] = {'a', 'b', 'c', 'd'};
    std::size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Original char array: ";
    iter(charArray, charArrayLength, print<char>);
    std::cout << "\n";

    iter(charArray, charArrayLength, toUpperCase);

    std::cout << "Modified char array (uppercased): ";
    iter(charArray, charArrayLength, print<char>);
    std::cout << "\n";

    return 0;
}
