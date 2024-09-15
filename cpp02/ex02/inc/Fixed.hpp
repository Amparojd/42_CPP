/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:26:11 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 11:26:20 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;  // Valor en punto fijo
    static const int _fractionalBits = 8;  // Número de bits fraccionarios

public:
    Fixed();  // Constructor por defecto
    Fixed(const int intValue);  // Constructor para enteros
    Fixed(const float floatValue);  // Constructor para flotantes
    Fixed(const Fixed &other);  // Constructor de copia
    Fixed &operator=(const Fixed &other);  // Operador de asignación por copia
    ~Fixed();  // Destructor

    int getRawBits(void) const;  // Obtener valor crudo
    void setRawBits(int const raw);  // Establecer valor crudo

    float toFloat(void) const;  // Convertir a flotante
    int toInt(void) const;  // Convertir a entero

    // Sobrecarga de operadores de comparación
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Sobrecarga de operadores aritméticos
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Sobrecarga de operadores de incremento/decremento
    Fixed& operator++();  // Pre-incremento
    Fixed operator++(int);  // Post-incremento
    Fixed& operator--();  // Pre-decremento
    Fixed operator--(int);  // Post-decremento

    // Funciones miembro estáticas
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);

    // Sobrecarga del operador de inserción <<
    friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
};

#endif
