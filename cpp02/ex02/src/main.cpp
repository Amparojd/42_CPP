/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:27:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/20 22:26:31 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/*int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}*/

#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2)); // Multiplicación: 5.05 * 2

    std::cout << "Valor inicial de a: " << a << std::endl;

    std::cout << "Realizando el pre-incremento de a" << std::endl;
    std::cout << "a después del pre-incremento (operación: a + 1): " << ++a << std::endl; // Pre-incremento

    std::cout << "Valor de a después del pre-incremento: " << a << std::endl;

    std::cout << "Realizando el post-incremento de a." << std::endl;
    std::cout << "Valor de a durante el post-incremento (operación: a antes de incrementar): " << a++ << std::endl; // Post-incremento

    std::cout << "Valor de a después del post-incremento: " << a << std::endl;
    std::cout << "Valor de b (resultado de 5.05f * 2): " << b << std::endl; // Resultado de la multiplicación

    std::cout << "Calculando el máximo entre a y b." << std::endl;
    std::cout << "El máximo es: " << Fixed::max(a, b) << std::endl; // Comparación

    return 0;
}
