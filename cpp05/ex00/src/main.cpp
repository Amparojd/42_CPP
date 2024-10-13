/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:39:00 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 12:00:12 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Juan", 50);
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;
        std::cout << std::endl;

        //Second example
        Bureaucrat bureaucrat2("Ana", 50);
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << "After decrement: " << bureaucrat2 << std::endl;
        std::cout << std::endl;

        // Testing exceptions
        Bureaucrat highBureaucrat("Javi", 1);
        std::cout << highBureaucrat << " e intenamos incrementar su grado..." << std::endl;
        highBureaucrat.incrementGrade(); // Should throw exception
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
        std::cout << std::endl;
    try {
        Bureaucrat lowBureaucrat("Paco", 150);
        std::cout << lowBureaucrat << " Intentamos decrementar su grado..." << std::endl;

        lowBureaucrat.decrementGrade(); // Should throw exception
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
