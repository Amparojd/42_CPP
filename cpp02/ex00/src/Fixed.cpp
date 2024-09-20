/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:11:01 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/16 19:11:49 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Constructor por defecto
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor de copia
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

// Operador de asignación por copia
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Obtener valor crudo
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

// Establecer valor crudo
void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

