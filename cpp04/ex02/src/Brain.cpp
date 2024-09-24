/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:00:00 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 20:00:00 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain() {
    std::ostringstream oss;  // Crear un objeto ostringstream
    for (int i = 0; i < 100; ++i) {
        oss.str("");  // Limpiar el stream
        oss << "Idea " << (i + 1);  // Convertir el número a string
        ideas[i] = oss.str();  // Asignar el resultado al arreglo
    }
    std::cout << PURPLE << "Brain created." << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
    std::cout << PURPLE <<  "Brain copied.(copy constructor)" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    std::cout << PURPLE << "Brain assigned.(Copy Assignment Operator)" << RESET << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << RED << "Brain destroyed." << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index]; // Retorna la idea en el índice proporcionado
    }
    return ""; // Retorna vacío si el índice es inválido
}

void Brain::showIdeas() const {
    for (int i = 0; i < 100; i++) {
        std::cout << "Idea " << i + 1 << ": " << ideas[i] << std::endl;
    }
}

