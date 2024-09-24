/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:01 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/24 10:42:24 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << GREEN << BOLD << "Animal constructor created." << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
    std::cout << GREEN << "Animal copied. (copy constructor)" << RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << GREEN << "Animal assigned.(Copy Assignment Operator)" << RESET << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << RED << "Animal destroyed." << RESET << std::endl;
}

//Al ser clase abstracta esto no lo implementaríamos
/*void Animal::makeSound() const {
    std::cout << " 🤨 I can't determine what sound Animal should make, it's too generic!" << std::endl;
}*/

std::string AAnimal::getType() const {
    return type;
}
