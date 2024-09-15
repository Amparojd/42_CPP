/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:14 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:41:14 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog();
    Dog(const Dog &other);
    virtual ~Dog();

    Dog& operator=(const Dog &other);
    virtual void makeSound() const;
};

#endif // DOG_HPP
