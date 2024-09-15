/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:22:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 11:22:27 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>  // Para roundf

// Constructor por defecto
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor para enteros
Fixed::Fixed(const int intValue) : _fixedPointValue(intValue << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// Constructor para flotantes
Fixed::Fixed(const float floatValue) : _fixedPointValue(static_cast<int>(roundf(floatValue * (1 << _fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;
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
    return _fixedPointValue;
}

// Establecer valor crudo
void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

// Convertir a flotante
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// Convertir a entero
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Sobrecarga del operador de inserción <<
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}


