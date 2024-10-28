/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:24:02 by vpeinado          #+#    #+#             */
/*   Updated: 2024/10/28 18:08:21 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

// Función generate: genera aleatoriamente una instancia de A, B o C
Base *generate(void) 
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int randValue = std::rand() % 3;
    switch (randValue)
	 {
		case 0:
        	return new A();
			break;
		case 1:
        	return new B();
			break;
		case 2:
        	return new C();
			break;
	 }
		return NULL;
}

// Identifica el tipo usando punteros
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}


void identify(Base &p){
	try{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Class A" << std::endl;
		return;
	}catch(std::exception &e){};
	try{
		B b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Class B" << std::endl;
		return;
	}catch(std::exception &e){};
	try{
		C c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Class C" << std::endl;
		return;
	}catch(std::exception &e){};
	std::cerr << "unknown reference" << std::endl;
}