/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:24:14 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/16 18:42:25 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug( void ) {
    std::cout << GREEN <<"DEBUG: 😋🍔 I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RESET << std::endl;
}

void Harl::info( void ) {
    std::cout << CYAN << "INFO: 🤨 I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void Harl::warning( void ) {
    std::cout << YELLOW << "WARNING: 😡 I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void Harl::error( void ) {
    std::cout << RED << "ERROR: 🤬 This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*logCatLevels[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i < 4; i++)
	{
		if(level == levels[i])
		{
			(this->*logCatLevels[i])();
			return;
		}
	}
	if(level != "EXIT")
	{
		std::cout << "[ 🥺 Harl have several problems to understand this command 🥺 ]" << std::endl;
		std::cout << std::endl;
	}
}