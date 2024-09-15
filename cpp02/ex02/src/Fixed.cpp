/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:26:53 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 11:27:31 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>  // Para roundf

// Constructor por defecto
Fixed::Fixed() : _fixedPointValue(0) {}

// Constructor para enteros
Fixed::Fixed(const int intValue) : _fixedPointValue(intValue << _fractionalBits) {}

// Constructor para flotantes
Fixed::Fixed(const float floatValue) : _fixedPointValue(static_cast<int>(roundf(floatValue * (1 << _fractionalBits)))) {}

// Constructor de copia
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue) {}

// Operador de asignación por copia
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {}

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

// Sobrecarga de operadores de comparación
bool Fixed::operator>(const Fixed &other) const {
    return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _fixedPointValue != other._fixedPointValue;
}

// Sobrecarga de operadores aritméticos
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = _fixedPointValue + other._fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = _fixedPointValue - other._fixedPointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = (static_cast<long long>(_fixedPointValue) * other._fixedPointValue) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = (static_cast<long long>(_fixedPointValue) << _fractionalBits) / other._fixedPointValue;
    return result;
}

// Sobrecarga de operadores de incremento/decremento
Fixed& Fixed::operator++() {  // Pre-incremento
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {  // Post-incremento
    Fixed temp = *this;
    ++_fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--() {  // Pre-decremento
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {  // Post-decremento
    Fixed temp = *this;
    --_fixedPointValue;
    return temp;
}

// Funciones miembro estáticas
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Sobrecarga del operador de inserción <<
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
