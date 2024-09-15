/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:31:46 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:40:55 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();

    Animal& operator=(const Animal &other);
    std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif

