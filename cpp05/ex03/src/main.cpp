/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:34:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/12 17:13:28 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

void testBureaucratAndForms() {
    try {
        Bureaucrat bob("Bob", 30);
        Bureaucrat alice("Alice", 50);
        
        // Crear un intern
        Intern intern;

        // Crear un formulario de creación de arbustos
        AForm* shrubForm = intern.makeForm("shrubbery creation", "Home");
        if (shrubForm) {
            bob.signForm(*shrubForm);
            bob.executeForm(*shrubForm);
            delete shrubForm; // Liberar memoria
        }

        // Crear un formulario de solicitud de robotomía
        AForm* robotomyForm = intern.makeForm("robotomy request", "Bender");
        if (robotomyForm) {
            bob.signForm(*robotomyForm);
            bob.executeForm(*robotomyForm);
            delete robotomyForm; // Liberar memoria
        }

        // Crear un formulario de perdón presidencial
        AForm* pardonForm = intern.makeForm("presidential pardon", "Zaphod");
        if (pardonForm) {
            bob.signForm(*pardonForm);
            bob.executeForm(*pardonForm);
            delete pardonForm; // Liberar memoria
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testBureaucratGrade() {
    try {
        Bureaucrat john("John", 150); // Debería ser un grado bajo
        Bureaucrat jane("Jane", 1);   // Debería ser un grado alto

        // Creación de un formulario de robotomía
        RobotomyRequestForm robotomy("Target");

        // Prueba de firma
        john.signForm(robotomy); // Debería fallar
        jane.signForm(robotomy);  // Debería tener éxito

        // Prueba de ejecución
        john.executeForm(robotomy); // Debería fallar
        jane.executeForm(robotomy);  // Debería tener éxito

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Inicializar el generador de números aleatorios

    std::cout << "=== Test Bureaucrat and Forms ===" << std::endl;
    testBureaucratAndForms();

    std::cout << std::endl;

    std::cout << "=== Test Bureaucrat Grade ===" << std::endl;
    testBureaucratGrade();

    return 0;
}
