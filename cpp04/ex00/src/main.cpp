/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:35:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:35:05 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Test with Animal, Dog, and Cat
    std::cout << "Creating Animal, Dog, and Cat objects:" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;

    std::cout << "Making sounds:" << std::endl;
    i->makeSound(); // Should print Cat sound
    j->makeSound(); // Should print Dog sound
    meta->makeSound(); // Should print generic animal sound

    delete i;
    delete j;
    delete meta;

    // Test with WrongAnimal and WrongCat
    std::cout << "Creating WrongAnimal and WrongCat objects:" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;

    std::cout << "Making sounds:" << std::endl;
    wrongCat->makeSound(); // Should print WrongCat sound
    wrongMeta->makeSound(); // Should print WrongAnimal sound

    delete wrongCat;
    delete wrongMeta;

    return 0;
}
