/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:21:33 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/20 20:49:25 by ampjimen         ###   ########.fr       */
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

    void print(std::ostream &os) const;  // Método para imprimir

private:
    int myRound(float value) const;  // Función de redondeo
};

#endif


