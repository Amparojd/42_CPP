/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:22:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/20 21:11:21 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Constructor por defecto
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor para enteros
Fixed::Fixed(const int intValue) : _fixedPointValue(intValue << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// Constructor para flotantes
Fixed::Fixed(const float floatValue) : _fixedPointValue(myRound(floatValue * (1 << _fractionalBits))) {
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

int Fixed::toInt(void) const {
    return myRound(this->toFloat());
}

// Método para imprimir
void Fixed::print(std::ostream &os) const {
    os << this->toFloat();
}

// Función de redondeo
int Fixed::myRound(float value) const {
    return static_cast<int>(value >= 0 ? value + 0.5f : value - 0.5f);
}
