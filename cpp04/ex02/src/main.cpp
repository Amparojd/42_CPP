/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:35:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/24 10:40:46 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << GRAY << BOLD << ITALIC << "**** TEST 1: Creating and using Animal, Dog, and Cat objects ****\n" << RESET << std::endl;

    AAnimal *animals[6];
    for(int i = 0; i < 3; ++i) {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for(int i = 3; i < 6; ++i) {
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    for (int i = 0; i < 6; ++i) {
        std::cout << BOLD << "Animal Type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
        
    }
    std::cout << std::endl;

    // Cleaning up
    for (int i = 0; i < 6; ++i) {
        delete animals[i];
    }
    std::cout << std::endl;
    
    ////////////////////////////////////////////////////////////////////////////
    std::cout << GRAY << ITALIC << "**** TEST 2: Copy constructor and assignment operator ****" << RESET << std::endl;

    Cat basic;
    {
        Cat tmp = basic; // This should invoke the copy constructor
        std::cout << "After copying, tmp's type: " << tmp.getType() << std::endl;
        tmp.makeSound();
        tmp.showIdeas();
    } // tmp goes out of scope here, should delete its own Brain
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////
    std::cout << GRAY << ITALIC << "**** TEST 3: Check for deep copy ****\n" << RESET <<  std::endl;
    Dog original;
    original.showIdeas();
    
    Dog copy;
    
    copy = original; // This should invoke the copy assignment
    
    copy.showIdeas();
    std::cout << "Original and copy types: " << original.getType() << " and " << copy.getType() << std::endl;
    std::cout << "\nAssigned 'original' Dog to 'copy' Dog." << std::endl;
    std::cout << std::endl;

    /////////////////////////////////////////////////////////////////////////////////
    // Add the additional test for Cat copy
    std::cout << GRAY << BOLD << ITALIC << "**** TEST 4: Creating and using Cat objects with copy ****\n" << RESET << std::endl;

    Cat originalCat;
    std::cout << "Original Cat's ideas:" << std::endl;
    originalCat.showIdeas();

    // Hacemos una copia profunda de 'originalCat'
    Cat copyCat = originalCat; // Esto llamará al constructor de copia

    std::cout << "\nAfter copying:\n" << std::endl;
    std::cout << "Original Cat's ideas:" << std::endl;
    originalCat.showIdeas();

    std::cout << "\nCopied Cat's ideas:" << std::endl;
    copyCat.showIdeas();

    std::cout << "\nModifying ideas of the copy..." << std::endl;

    copyCat.setIdea(0, "New Idea for Copy Cat");

    std::cout << "\nAfter modification:\n" << std::endl;
    std::cout << "Original Cat's ideas:" << std::endl;
    originalCat.showIdeas();

    std::cout << "\nCopied Cat's ideas:" << std::endl;
    copyCat.showIdeas();

    return 0;
}


/*int main() {
    std::cout << GRAY << BOLD << ITALIC << "**** TEST 1: Creating an Animal object ****\n" << RESET << std::endl;

    Animal* animal = new Animal();
    std::cout << "Animal created successfully." << std::endl;
    animal->makeSound();
    delete animal;

    return 0;
}*/

