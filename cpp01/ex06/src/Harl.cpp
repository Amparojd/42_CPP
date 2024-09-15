/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:31:16 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/12 21:09:22 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    // Array de punteros a funciones miembro
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Array de niveles correspondientes
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    // Determinar el índice del nivel de log proporcionado
    int levelIndex = -1;
    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            levelIndex = i;
            break;
        }
    }

    // Imprimir desde el nivel actual hasta el nivel más grave
    switch (levelIndex) {
        case 0:
            (this->*functions[0])();
            // Fall through
        case 1:
            (this->*functions[1])();
            // Fall through
        case 2:
            (this->*functions[2])();
            // Fall through
        case 3:
            (this->*functions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
