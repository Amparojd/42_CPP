/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:40:20 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 18:56:38 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstring>
#include <iostream>

Brain::Brain() {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "Empty idea";
    }
    std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain &other) {
    copyIdeas(other);
    std::cout << "Brain copy constructor called." << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
    if (this != &other) {
        copyIdeas(other);
    }
    return *this;
}

void Brain::copyIdeas(const Brain &other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}
