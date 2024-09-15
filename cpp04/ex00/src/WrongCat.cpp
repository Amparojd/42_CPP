/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:34:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:34:51 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow! Meow! (wrong sound)" << std::endl;
}
