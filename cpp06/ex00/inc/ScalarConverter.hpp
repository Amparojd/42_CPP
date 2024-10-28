/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:01:01 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/27 21:08:44 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cmath>

// Define colors
#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define CYAN        "\033[96m"
#define PURPLE      "\033[95m"
#define GRAY        "\033[90m"
#define BOLD        "\033[1m"
#define ITALIC      "\033[3m"

class ScalarConverter {
    private:

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &rhs);

    public:
    
        static void convert(std::string const &ref);
        static std::string getType(std::string const &ref);
        static bool isInt(std::string const &ref);
        static bool isFloat(std::string const &ref);
        static bool isDouble(std::string const &ref);
        static void printChar(std::string const &ref);
        static void printInt(std::string const &ref);
        static void printFloat(std::string const &ref);
        static void printDouble(std::string const &ref);
        static void printPseudoDouble(std::string const &ref);
        static void printPseudoFloat(std::string const &ref);

        class ImpossibleConversionException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        // podemos obviar crear una clase para la excepcion y usar directamente
        // throw std::runtime_error("impossible");
};

#endif