/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:39:00 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/23 19:03:31 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Bureaucrat.hpp"

int main() {
    std::cout << "======= First example =======" << std::endl;
    try {
        Bureaucrat bureaucrat("Juan", 50);
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception &e) 
    {
        std::cerr << "Error with bureaucrat : " << e.what() << std::endl;
    }

    std::cout << "======= Second example =======" << std::endl;

    try
    {
        Bureaucrat bureaucrat2("Ana", 50);
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << "After decrement: " << bureaucrat2 << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception &e) 
    {
        std::cerr << "Error with bureaucrat : " << e.what() << std::endl;
    }

    std::cout << "======= test exception 1 =======" << std::endl;
    try
    {
        Bureaucrat highBureaucrat("Javi", 1);
        std::cout << highBureaucrat << std::endl;
        highBureaucrat.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error with bureaucrat : " << e.what() << std::endl;

    }
    std::cout << std::endl;
    std::cout << "======= Test exception 2 =======" << std::endl;

    try {
        Bureaucrat lowBureaucrat("Paco", 145);
        for (int i = 0; i < 20; i++)
			{
				std::cout << lowBureaucrat << std::endl;
				lowBureaucrat.decrementGrade();
			}
        } catch (const std::exception &e) 
        {
            std::cerr << "Error with bureaucrat : " << e.what() << std::endl;
        }
    return 0;
}
