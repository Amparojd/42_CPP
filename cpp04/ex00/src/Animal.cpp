/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:01 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 19:35:04 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//Animal::Animal()  {}

Animal::Animal() : type("Animal") {
    std::cout << GREEN << BOLD << "Animal constructor created." << RESET << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copied." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal assigned." << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << RED << "Animal destroyed." << RESET << std::endl;
}

void Animal::makeSound() const {
    std::cout << " 🤨 I can't determine what sound Animal should make, it's too generic!" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
