/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:35:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:41:54 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    std::cout << "Creating an array of Animals (5 Dogs and 5 Cats):" << std::endl;
    for (int i = 0; i < numAnimals; ++i) {
        if (i < numAnimals / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    std::cout << "Making sounds:" << std::endl;
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "Deleting all Animals:" << std::endl;
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}
