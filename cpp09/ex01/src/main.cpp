/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:15:33 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/12 21:00:28 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./RPN ['list of numbers']" << std::endl;
        return 1;
    } 
    std::string str;
    for (int i = 1; i < argc; i++)
    {
        str += argv[i];
        if (i < argc - 1)
            str += " ";
    }
    
    RPN rpn(str);
    try {
        rpn.calculate();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}