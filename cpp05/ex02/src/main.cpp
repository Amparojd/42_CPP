/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:34:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 18:55:44 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

/*int main()
{
        srand(time(0));
        std::cout << "=======   We created 3 bureaucrats   ======" << std::endl;
        Bureaucrat juan("Juan", 150);
        Bureaucrat alicia("Alicia", 80);
        Bureaucrat edu("Edu", 5);
        std::cout << juan << std::endl;
        std::cout << alicia << std::endl;
        std::cout << edu << std::endl;
        std::cout << std::endl;

        std::cout << "=======   We created the forms   ======" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("target");
        PresidentialPardonForm pardon("criminal");
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "======= Test for Juan ========" << std::endl;
        std::cout << std::endl;

        std::cout << juan << std::endl;
        try {
            std::cout << "=== " << juan.getName() << " Attempts to sign the form: " << shrubbery.getName() << " ===" << std::endl;
            juan.signForm(shrubbery);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            std::cout << "=== " << juan.getName() << " Attempting to execute the form: " << shrubbery.getName() << " ===" << std::endl;
            juan.executeForm(shrubbery);

        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << juan.getName() << " Attempts to sign the form: " << robotomy.getName() << " ===" << std::endl;
            juan.signForm(robotomy);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << juan.getName() << " Attempting to execute the form: " << robotomy.getName() << " ===" << std::endl;
            juan.executeForm(robotomy);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << juan.getName() << " Attempts to sign the form: " << pardon.getName() << " ===" << std::endl;
            juan.signForm(pardon);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << juan.getName() << " Attempting to execute the form: " << pardon.getName() << " ===" << std::endl;
            juan.executeForm(pardon);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        
        std::cout << std::endl;
        
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << std::endl;
        std::cout << "======= Test for Alicia ========" << std::endl;
        try {
            std::cout << "=== " << alicia.getName() << " Attempts to sign the form: " << shrubbery.getName() << " ===" << std::endl;
            alicia.signForm(shrubbery);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alicia.getName() << " Attempting to execute the form: " << shrubbery.getName() << " ===" << std::endl;
            alicia.executeForm(shrubbery);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alicia.getName() << " Attempts to sign the form: " << robotomy.getName() << " ===" << std::endl;
            alicia.signForm(robotomy);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alicia.getName() << " Attempting to execute the form: " << robotomy.getName() << " ===" << std::endl;
            alicia.executeForm(robotomy);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alicia.getName() << " Attempts to sign the form: " << pardon.getName() << " ===" << std::endl;
            alicia.signForm(pardon);
        } catch (std::exception &e) {
            std::cerr <<  e.what() << std::endl;
        }

        try {
            std::cout << "=== " << alicia.getName() << " Attempting to execute the form: " << pardon.getName() << " ===" << std::endl;
            alicia.executeForm(pardon);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << std::endl;
        
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << std::endl;
        std::cout << "======= Test for Edu ========" << std::endl;
        try {
            std::cout << "=== " << edu.getName() << " Attempts to sign the form: " << shrubbery.getName() << " ===" << std::endl;
            edu.signForm(shrubbery);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << edu.getName() << " Attempting to execute the form: " << shrubbery.getName() << " ===" << std::endl;
            edu.executeForm(shrubbery);        
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << edu.getName() << " Attempts to sign the form: " << robotomy.getName() << " ===" << std::endl;
            edu.signForm(robotomy);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << edu.getName() << " Attempting to execute the form: " << robotomy.getName() << " ===" << std::endl;
            edu.executeForm(robotomy);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << edu.getName() << " Attempts to sign the form: " << pardon.getName() << " ===" << std::endl;
            edu.signForm(pardon);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            std::cout << "=== " << edu.getName() << " Attempting to execute the form: " << pardon.getName() << " ===" << std::endl;
            edu.executeForm(pardon);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << std::endl;
        
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
        
    return 0;
}*/

int main()
{
    srand(time(0));
    try {
        Bureaucrat juan("Juan", 1);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Robotomy");
        PresidentialPardonForm pardon("criminal ");

        std::cout << "Juan's tests:" << std::endl;
        juan.signForm(shrubbery);
        juan.executeForm(shrubbery);

        std::cout << std::endl;

        juan.signForm(robotomy);
        juan.executeForm(robotomy);

        std::cout << std::endl;

        juan.signForm(pardon);
        juan.executeForm(pardon);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception for Juan: " << e.what() << std::endl;
    }
}