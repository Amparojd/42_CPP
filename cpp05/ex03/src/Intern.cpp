/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:59:20 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/21 19:55:25 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    // Estructura de datos para mapear los nombres de formularios con funciones de creación
    std::string formNames[3] = {
        "shrubbery creation", 
        "robotomy request", 
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string &target) = {
        &ShrubberyCreationForm::create,
        &RobotomyRequestForm::create,
        &PresidentialPardonForm::create
    };

    // Buscar el formulario por el _name
    for (int i = 0; i < 3; ++i) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target); // Llamar a la función adecuada
        }
    }

    // Si el formulario no existe, imprimir error
    std::cerr << "Error: form " << formName << " doesn't exist." << std::endl;
    return NULL;
}
