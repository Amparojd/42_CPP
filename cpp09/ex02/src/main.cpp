/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:19:49 by ampjimen          #+#    #+#             */
/*   Updated: 2024/12/13 19:53:30 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Empty string" << std::endl;
        std::cerr << "Usage: ./PmergeMe [positive integer sequence]" << std::endl;
        return 1;
    }
    std::string input;
    std::vector<int> seenNumbers;
    // Construimos el string de entrada a partir de los argumentos
    for (int i = 1; i < argc; ++i) {
        int num;
        std::stringstream ss(argv[i]);
        
        // Intentamos convertir el argumento a número
        ss >> num;
        
        // Comprobamos si la conversión es exitosa y si el número es positivo
        if (ss.fail() || num <= 0) {
            std::cerr << "Error: Negative or zero values are not allowed" << std::endl;
            return 1;
        }
        // Verificar si el número está repetido
        /*bool isDuplicate = false;
        for (size_t j = 0; j < seenNumbers.size(); ++j) {
            if (seenNumbers[j] == num) {
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate) {
            std::cerr << "Error: Duplicate values are not allowed" << std::endl;
            return 1;
        }*/
        seenNumbers.push_back(num);
        
        if (i > 1) {
            input += " "; // añadimos espacio entre números
        }
        input += argv[i];
    }
    /*if (argc == 2) {
        std::cerr << "Error: Only one element in the container" << std::endl;
        return 1;
    }*/
    // Creamos el objeto PmergeMe y pasamos el string
    PmergeMe sorter(input);
    sorter.init();

    return 0;
}
