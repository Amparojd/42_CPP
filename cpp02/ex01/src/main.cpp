/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:22:42 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/20 21:54:10 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.7321f);

    std::cout << "a is ";
    a.print(std::cout);
    std::cout << std::endl;
    
    std::cout << "b is ";
    b.print(std::cout);
    std::cout << std::endl;

    std::cout << "c is ";
    c.print(std::cout);
    std::cout << std::endl;

    std::cout << "d is ";
    d.print(std::cout);
    std::cout << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}


/*int main(void) {
    Fixed a(1234.4321f);  // Inicializar a con un valor flotante

    // Mostrar el valor crudo
    std::cout << "static_cast<int>(1234.4321 * 256 - 0.5);" << std::endl;
    std::cout << "Valor crudo de a: " << a.getRawBits() << std::endl;
    std::cout << std::endl;
    
    // Convertir a float
    float floatValue = a.toFloat();
    std::cout << "static_cast<float>(316049) / 256;" << std::endl;
    std::cout << "Valor de a como float: " << floatValue << std::endl;
    std::cout << std::endl;
    
    // Convertir a int
    int intValue = a.toInt();
        std::cout << "static_cast<float>(316049) / 256 - 0.5;" << std::endl;
    std::cout << "Valor de a como int: " << intValue << std::endl;

    return 0;
}*/
