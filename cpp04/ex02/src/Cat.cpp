/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:33:04 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/24 10:42:57 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << YELLOW << " Cat created." << RESET << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
    brain = new Brain(*other.brain);
    std::cout << YELLOW << "Cat copied.(copy constructor)" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << YELLOW << "Cat assigned.(Copy Assignment Operator)" << RESET << std::endl;
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << RED <<  "Cat destroyed." << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << YELLOW <<  " 🐱 Meow! Meow!" << RESET << std::endl;
}

//new
void Cat::showIdeas() const {
    for (int i = 0; i < 10; ++i) { // Muestra las primeras 10 ideas
        std::cout << "Cat's idea at index " << i << ": " << brain->getIdea(i) << std::endl;
    }
}

void Cat::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea); // Llama al método de Brain para establecer la idea
}

