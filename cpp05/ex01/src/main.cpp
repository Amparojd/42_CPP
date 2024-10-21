/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:34:31 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/21 19:27:47 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"


int main() {
    std::cout <<  "====== First example ======" << std::endl;
    try {
        Bureaucrat juan("Juan", 55);
        std::cout << juan << std::endl;

        Form taxForm("Tax Form 1", 50, 30);
        std::cout << taxForm << std::endl;
        
        juan.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception &e) 
    {
        std::cerr << "Caught Exception:" << e.what() << std::endl;
    }
    
    std::cout <<  "====== Second example ======" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 30);
        std::cout << alice << std::endl;
        
        Form taxForm2("Tax Form 2", 50, 30);
        std::cout << taxForm2 << std::endl;

        alice.signForm(taxForm2);
        std::cout << taxForm2 << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Caught Exception:" << e.what() << std::endl;
    }

    return 0;
}

