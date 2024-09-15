/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:01:57 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/12 20:14:39 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << "----------HEAP----------" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    std::cout << std::endl;
    
    std::cout << "---------STACK----------" << std::endl;
    randomChump("StackZombie");
    std::cout << std::endl;
    return 0;
}

/*int main() {
    std::cout << "----------HEAP----------" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    // Comportamiento indefinido: usar el puntero después de hacer delete
    std::cout << "Trying to use heapZombie after deletion (undefined behavior):" << std::endl;
    heapZombie->announce(); // Comportamiento indefinido
    std::cout << std::endl;

    return 0;
}*/

/*int main()
{
    std::cout << "---------STACK----------" << std::endl;
    Zombie* invalidStackZombiePtr = NULL;

    {
        Zombie stackZombie = Zombie("StackZombie");
        invalidStackZombiePtr = &stackZombie; // Guardando la dirección de un objeto del stack
        stackZombie.announce(); // Llamada válida: dentro del alcance
    } // Aquí stackZombie se destruye

    std::cout << "Trying to use a zombie after it goes out of scope (undefined behavior):" << std::endl;
    invalidStackZombiePtr->announce(); // Comportamiento indefinido: el objeto ya no existe
    std::cout << std::endl;
}*/
