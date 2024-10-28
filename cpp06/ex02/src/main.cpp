/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:00:26 by vpeinado          #+#    #+#             */
/*   Updated: 2024/10/28 17:59:11 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Base.hpp"
#include <iostream>

extern Base* generate();
extern void identify(Base* p);
extern void identify(Base& p);

int main() {
    Base* basePtr = generate();  // Genera una instancia aleatoria
    std::cout << "Identify using pointer: ";
    identify(basePtr);  // Identifica usando puntero

    std::cout << "Identify using reference: ";
    identify(*basePtr);  // Identifica usando referencia

    delete basePtr;  // Liberar la memoria asignada
    return 0;
}
