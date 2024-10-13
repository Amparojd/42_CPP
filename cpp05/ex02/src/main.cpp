/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:34:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 12:54:58 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:34:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 12:00:00 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:34:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 12:00:00 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main() {
    try {
        // Creación de burócratas
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 20);
        Bureaucrat charlie("Charlie", 150); // Charlie tiene el grado más bajo
        std::cout << "=======   Creamos 3 burócratas   ======" << std::endl;
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << charlie << std::endl;
        std::cout << std::endl;

        // Creación de formularios
        std::cout << "=======   Creamos los formularios   ======" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("target");
        PresidentialPardonForm pardon("criminal");
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
        std::cout << std::endl;

         std::cout << std::endl;
        std::cout << "======= Test para Bob ========" << std::endl;
        std::cout << bob << std::endl;
        try {
            std::cout << "=== " << bob.getName() << " intenta firmar el formulario: " << shrubbery.getName() << " ===" << std::endl;
            bob.signForm(shrubbery);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << bob.getName() << " no pudo firmar " << shrubbery.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << bob.getName() << " intenta ejecutar el formulario: " << shrubbery.getName() << " ===" << std::endl;
            bob.executeForm(shrubbery);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << bob.getName() << " no pudo ejecutar " << shrubbery.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << bob.getName() << " intenta firmar el formulario: " << robotomy.getName() << " ===" << std::endl;
            bob.signForm(robotomy);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << bob.getName() << " no pudo firmar " << robotomy.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << bob.getName() << " intenta ejecutar el formulario: " << robotomy.getName() << " ===" << std::endl;
            bob.executeForm(robotomy);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << bob.getName() << " no pudo ejecutar " << robotomy.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << bob.getName() << " intenta firmar el formulario: " << pardon.getName() << " ===" << std::endl;
            bob.signForm(pardon);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << bob.getName() << " no pudo firmar " << pardon.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << bob.getName() << " intenta ejecutar el formulario: " << pardon.getName() << " ===" << std::endl;
            bob.executeForm(pardon);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << bob.getName() << " no pudo ejecutar " << pardon.getName() << " porque " << e.what() << std::endl;
        }

         std::cout << std::endl;
        std::cout << "======= Test para Alice ========" << std::endl;
        try {
            std::cout << "=== " << alice.getName() << " intenta firmar el formulario: " << shrubbery.getName() << " ===" << std::endl;
            alice.signForm(shrubbery);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << alice.getName() << " no pudo firmar " << shrubbery.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alice.getName() << " intenta ejecutar el formulario: " << shrubbery.getName() << " ===" << std::endl;
            alice.executeForm(shrubbery);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << alice.getName() << " no pudo ejecutar " << shrubbery.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alice.getName() << " intenta firmar el formulario: " << robotomy.getName() << " ===" << std::endl;
            alice.signForm(robotomy);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << alice.getName() << " no pudo firmar " << robotomy.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alice.getName() << " intenta ejecutar el formulario: " << robotomy.getName() << " ===" << std::endl;
            alice.executeForm(robotomy);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << alice.getName() << " no pudo ejecutar " << robotomy.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alice.getName() << " intenta firmar el formulario: " << pardon.getName() << " ===" << std::endl;
            alice.signForm(pardon);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << alice.getName() << " no pudo firmar " << pardon.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alice.getName() << " intenta ejecutar el formulario: " << pardon.getName() << " ===" << std::endl;
            alice.executeForm(pardon);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << alice.getName() << " no pudo ejecutar " << pardon.getName() << " porque " << e.what() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "======= Test para Charlie ========" << std::endl;
        try {
            std::cout << "=== " << charlie.getName() << " intenta firmar el formulario: " << shrubbery.getName() << " ===" << std::endl;
            charlie.signForm(shrubbery);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << charlie.getName() << " no pudo firmar " << shrubbery.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << charlie.getName() << " intenta ejecutar el formulario: " << shrubbery.getName() << " ===" << std::endl;
            charlie.executeForm(shrubbery);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << charlie.getName() << " no pudo ejecutar " << shrubbery.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << charlie.getName() << " intenta firmar el formulario: " << robotomy.getName() << " ===" << std::endl;
            charlie.signForm(robotomy);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << charlie.getName() << " no pudo firmar " << robotomy.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << charlie.getName() << " intenta ejecutar el formulario: " << robotomy.getName() << " ===" << std::endl;
            charlie.executeForm(robotomy);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << charlie.getName() << " no pudo ejecutar " << robotomy.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << charlie.getName() << " intenta firmar el formulario: " << pardon.getName() << " ===" << std::endl;
            charlie.signForm(pardon);
            std::cout << "Formulario firmado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << charlie.getName() << " no pudo firmar " << pardon.getName() << " porque " << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << charlie.getName() << " intenta ejecutar el formulario: " << pardon.getName() << " ===" << std::endl;
            charlie.executeForm(pardon);
            std::cout << "Formulario ejecutado con éxito." << std::endl;
        } catch (std::exception &e) {
            std::cerr << charlie.getName() << " no pudo ejecutar " << pardon.getName() << " porque " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << "Error en el programa: " << e.what() << std::endl;
    }

    return 0;
}

