/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:39:07 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/28 20:39:17 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // Debería imprimir 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // Debería imprimir 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Usando iteradores para imprimir los elementos
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Crear un stack normal a partir del MutantStack
    std::stack<int> s(mstack);

    return 0;
}
