/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:00:54 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/28 19:18:41 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../inc/Array.hpp"
#include <ctime>
#include <cstdlib>

/*#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/

int main() {
    try {
        Array<int> intArray(5); // Crea un array de 5 enteros
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i + 1; // Inicializa los valores
        }

        std::cout << "intArray: ";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " "; // Imprime los valores
        }
        std::cout << std::endl;

        // Prueba de manejo de excepciones
        std::cout << "Accessing out of bounds index:" << std::endl;
        std::cout << intArray[10] << std::endl; // Esto debería lanzar una excepción
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl; // Manejo de excepciones
    }

    return 0;
}