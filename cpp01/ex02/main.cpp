/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:55:56 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/11 19:02:55 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    
    std::string str = "HI THIS IS BRAIN";
    

    std::string *stringPTR = &str; // pointer
    std::string &stringREF = str;  // Reference

    std::cout << "Memory address of string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "Value of string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}

