/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:25:21 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 21:10:22 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        srand((0));
        std::cout << "===TEST 1: Create and handle a ShrubberyCreationForm === " << std::endl;

        Bureaucrat alicia("Alicia", 150);
        std::cout << alicia << std::endl;

        // Create an Intern
        Intern intern;
                
        try {
            AForm *shrubberyForm = intern.makeForm("shrubbery creation", "home");
            alicia.signForm(*shrubberyForm);
            alicia.executeForm(*shrubberyForm);
            delete shrubberyForm;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "==== TEST 2: Create and handle a RobotomyRequestForm ===" << std::endl;
        try {
            AForm *robotomyForm = intern.makeForm("robotomy request", "Bender");
            alicia.signForm(*robotomyForm);
            alicia.executeForm(*robotomyForm);
            delete robotomyForm;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << " === TEST 3: Create and handle a PresidentialPardonForm === " << std::endl;
        try {
            AForm *presidentialForm = intern.makeForm("presidential pardon", "John Doe");
            alicia.signForm(*presidentialForm);
            alicia.executeForm(*presidentialForm);
            delete presidentialForm;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout <<  "=== TEST 4: Attempt to create an unknown form === " << std::endl;
        try {
            AForm *unknownForm = intern.makeForm("unknown form", "Nobody");
            if (unknownForm) {
                delete unknownForm;
            }
        } catch (const std::exception &e) {
            std::cerr <<  e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
