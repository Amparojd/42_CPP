/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:00:54 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/01 19:28:21 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../inc/Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 3

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
    std::cout << "Valores generados:\n";
    std::cout << "numbers: ";
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\nmirror: ";
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << mirror[i] << " ";
    }
    std::cout << std::endl;
    
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
    
    std::cout << "Probando acceso fuera de límites en 'numbers' " << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Intentando acceso a índice " << MAX_VAL << "...\n";
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Asignando nuevos valores aleatorios a 'numbers'.\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
        std::cout << numbers[i]  << ' ' << std::endl;

    }
    delete [] mirror;//
    return 0;
}

// int main() {
//     try {
//         Array<int> intArray(5);
//         for (unsigned int i = 0; i < intArray.size(); ++i) 
//         {
//             intArray[i] = i + 1;
//         }

//         std::cout << "intArray: ";
//         for (unsigned int i = 0; i < intArray.size(); ++i) 
//         {
//             std::cout << intArray[i] << " ";
//         }
//         std::cout << std::endl;

//         Prueba de manejo de excepciones
//         std::cout << "Accessing out of bounds index:" << std::endl;
//         std::cout << intArray[10] << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }