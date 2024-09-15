/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:25:02 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/11 19:00:06 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string baseName) {
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
    std::ostringstream oss;  // Crear un flujo de salida de string
    oss << baseName << (i + 1);  // Concatenar baseName y el número (i + 1)
    std::string name = oss.str();  // Convertir el contenido del flujo a una cadena
    horde[i].setName(name);  // Asignar el nombre al zombie
}

    return horde;
}