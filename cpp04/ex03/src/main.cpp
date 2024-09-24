/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:07:35 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/24 21:34:40 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {

    std::cout << GRAY << BOLD << ITALIC << "=== Inicio del programa ===" << RESET << std::endl;
    
    std::cout << GRAY << ITALIC << "Creando personaje Hero..." << RESET << std::endl;
    ICharacter* hero = new Character("Hero");
   
    
    std::cout << GRAY << ITALIC << "Creando personaje Villain..." << RESET << std::endl;
    ICharacter* villain = new Character("Villain");
   
    
    std::cout << GRAY << ITALIC << "Creando MateriaSource..." << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    
    // Aprendiendo nuevas materias
    std::cout << GRAY << ITALIC << "Aprendiendo materia Ice..." << RESET << std::endl;
    src->learnMateria(new Ice());
    
    std::cout << GRAY << ITALIC << "Aprendiendo materia Cure..." << RESET << std::endl;
    src->learnMateria(new Cure());


    std::cout << GRAY << ITALIC << "Creando materia de tipo 'ice' desde MateriaSource..." << RESET << std::endl;
    AMateria* iceMateria = src->createMateria("ice");
    AMateria* cureMateria = src->createMateria("cure");
    if (iceMateria) {
        std::cout << GRAY << "Equipando materia 'ice' a Hero..." << RESET << std::endl;
        hero->equip(iceMateria); // Equipando la materia
    }
    if (cureMateria) {
        std::cout << GRAY << "Equipando materia 'cure' a Hero..." << RESET << std::endl;
        hero->equip(cureMateria); // Equipando la materia
    }
    
    std::cout << GRAY << ITALIC << "Hero usando materia 'ice' en Villain..." << RESET << std::endl;
    hero->use(0, *villain); // Usar hielo
    
    std::cout << GRAY << ITALIC << "Hero usando materia 'cure' en Villain..." << RESET << std::endl;
    hero->use(1, *villain); // Usar cura
    
    
    std::cout << GRAY << ITALIC << "Eliminando personaje Villain..." << RESET << std::endl;
    delete villain; // Libera al villano
    
    std::cout << GRAY << ITALIC << "Eliminando personaje Hero y sus materias equipadas..." << RESET << std::endl;
    delete hero;    // Esto también libera las materias equipadas
    
    std::cout << GRAY << ITALIC << "Eliminando MateriaSource y sus materias almacenadas..." << RESET << std::endl;
    delete src;     // Libera MateriaSource (incluye liberar materias)

    return 0;
}






