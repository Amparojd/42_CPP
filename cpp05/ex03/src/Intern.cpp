/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:59:20 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 20:39:56 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const & src)
{
    *this = src;
}

Intern & Intern::operator=(Intern const & src)
{
	if (this != &src)
        *this = src;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) 
{
    std::string formNames[3] = {
        "shrubbery creation", 
        "robotomy request", 
        "presidential pardon"
    };

    for (int i(0); i < 3; i++) {
        if (formName == formNames[i]) 
        {
			switch(i)
			{
				case 0:
                    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
                    return new ShrubberyCreationForm(target);
				case 1:
                    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
                    return new RobotomyRequestForm(target);
				case 2:
                    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
					return new PresidentialPardonForm(target);
			}
        }
    }
    std::cerr << "Error: form " << formName << " doesn't exist." << std::endl;
    return NULL;
}
