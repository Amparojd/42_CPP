/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:10:37 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 11:17:38 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _fixedPointValue;  // Valor en punto fijo
    static const int _fractionalBits = 8;  // Número de bits fraccionarios

public:
    Fixed();  // Constructor por defecto
    Fixed(const Fixed &other);  // Constructor de copia
    Fixed &operator=(const Fixed &other);  // Operador de asignación por copia
    ~Fixed();  // Destructor

    int getRawBits(void) const;  // Obtener valor crudo
    void setRawBits(int const raw);  // Establecer valor crudo
};

#endif
