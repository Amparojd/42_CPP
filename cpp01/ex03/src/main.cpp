/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:21:41 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/31 21:44:45 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

int main()
{
    {
        std::cout << std::endl;
        std::cout << "------REFERENCE------" << std::endl;
        std::cout << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        std::cout << std::endl;
        std::cout << "------POINTER------" << std::endl;
        std::cout << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
        std::cout << std::endl;
        std::cout << "-POINTER WITHOUT WEAPON -" << std::endl;
        std::cout << std::endl;
        HumanB peter("Peter");
        peter.attack();
    }
    return 0;
}

// Este ejercicio implementa una simulación básica de un arma y dos tipos de humanos:
// HumanA y HumanB. Los detalles son los siguientes:

// 1. **Clase Weapon**:
//    - Atributo privado `type` que representa el tipo de arma.
//    - Métodos `getType()` para obtener el tipo de arma y `setType()` para cambiarlo.

// 2. **Clase HumanA**:
//    - Recibe una referencia a un objeto `Weapon` en su constructor, garantizando que siempre tendrá un arma.
//    - Método `attack()` que imprime el nombre del humano y el tipo de arma que usa.

// 3. **Clase HumanB**:
//    - Puede tener un puntero a `Weapon`, y el arma se asigna después de la creación del objeto mediante el método `setWeapon()`.
//    - El método `attack()` imprime el nombre del humano y el tipo de arma si está asignada, o un mensaje si no tiene arma.

// En el `main()` se crean instancias de estas clases y se prueba su funcionalidad, incluyendo el cambio del tipo de arma y los ataques resultantes.
