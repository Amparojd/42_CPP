/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:35:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/24 22:01:41 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;
}*/

int main()
{
    std::cout << GRAY << BOLD << ITALIC << "\n** TEST 1: Creating and using Animal, Dog, and Cat objects" << RESET << std::endl;

    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << GRAY << ITALIC << "\n** Dog Info and Sound **" << RESET << std::endl;
    std::cout << CYAN << "Object: " << dog->getType() << " " << RESET << std::endl;
    std::cout << CYAN << "Dog makeSound(): ";
    dog->makeSound();

    std::cout << GRAY << ITALIC << "\n** Cat Info and Sound **" << RESET << std::endl;
    std::cout << YELLOW << "Object: " << cat->getType() << " " << std::endl;
    std::cout << "Cat makeSound(): ";
    cat->makeSound();

    std::cout << GRAY << ITALIC << "\n** Animal Info and Sound **" << RESET << std::endl;
    std::cout <<  "Animal makeSound(): ";
    meta->makeSound();

    std::cout << std::endl;
    delete meta;
    delete dog;
    delete cat;

    std::cout << GRAY << BOLD << ITALIC << "\n** TEST 2: Incorrect Polymorphism with WrongAnimal and WrongCat **" << RESET << std::endl;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();


    std::cout << GRAY << ITALIC << "\n** WrongAnimal Info and Sound **" << RESET << std::endl;
    std::cout << "Object: " << wrongMeta->getType() << " " << RESET << std::endl;
    std::cout << "wrongMeta makeSound(): ";
    wrongMeta->makeSound();

    std::cout << GRAY << ITALIC << "\n** WrongCat Info and Sound **" << RESET << std::endl;
    std::cout << "Object: " << wrongCat->getType() << " " << std::endl;
    std::cout << "wrongcat makeSound(): ";
    wrongCat->makeSound();
    std::cout << "This is not expected behavior!" << std::endl;

    std::cout << std::endl;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}
