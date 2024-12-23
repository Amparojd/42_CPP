/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:01:29 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/27 21:11:14 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return *this;
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

/////////////EXCEPCIONES
const char *ScalarConverter::ImpossibleConversionException::what() const throw()
{
    return RED "\nError: " RESET "Impossible conversion\n"
    "The input is not a valid scalar value";
}

/***************************
* Parse - Member functions *
***************************/

bool ScalarConverter::isInt(std::string const &ref)
{
    size_t i = 0;
    if(ref[i] == '+' || ref[i] == '-')
        i++;
    for(; i < ref.length(); i++)
        if(!isdigit(ref[i]))
            return false;
    return true;
}

bool ScalarConverter::isFloat(std::string const &ref)
{
    size_t i = 0;
    bool point = false;
    if(ref[i] == '+' || ref[i] == '-')
        i++;
    for(; i < ref.length(); i++) {
        if(ref[i] == '.' && !point) {
            point = true;
            i++;
        }
        if(ref[i] == '.' && point)
            return false;
        if(!isdigit(ref[i]) && ref[i] != '.' && ref[i] != 'f')
            return false;
    }
    if (ref[ref.length() - 1] != 'f')
        return false;
    return true;
}

bool ScalarConverter::isDouble(std::string const &ref)
{
    size_t i = 0;
    bool point = false;
    if(ref[i] == '+' || ref[i] == '-')
        i++;
    for(; i < ref.length(); i++) {
        if(ref[i] == '.' && !point) {
            point = true;
            i++;
        }
        if(ref[i] == '.' && point)
            return false;
        if(!isdigit(ref[i]) && ref[i] != '.')
            return false;
    }

    return true;
}

std::string ScalarConverter::getType(std::string const &ref)
{
    std::string type;

    if(ref == "inff" || ref == "+inff" || ref == "-inff" || ref == "nanf")
        type = "pseudo_f";
    else if(ref == "inf" || ref == "+inf" || ref == "-inf" || ref == "nan")
        type = "pseudo_d";
    else if(ref.length() == 1 && !isdigit(ref[0]))
        type = "char";
    else if(isInt(ref))
        type = "int";
    else if(isFloat(ref))
        type = "float";
    else if(isDouble(ref))
        type = "double";
    else
        type = "impossible";
    return type;
}

/***************************
* Print - Member functions *
***************************/


/*
    No incluimos una compriobacion de los limites
         
    if(static_cast<int>(c) > static_cast<int>(std::numeric_limits<int>::max()))
        std::cout << "int: " << "Overflow" << std::endl;
    else if(static_cast<int>(c) < static_cast<int>(std::numeric_limits<int>::min()))
        std::cout << "int: " << "Underflow" << std::endl;

    ya que el rango de char estan muy por debajo del rango de int, nunca se produciria
    un overflow o underflow.
*/
void ScalarConverter::printChar(std::string const &ref)
{
    char c = ref[0];
    if(isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printInt(std::string const &ref)
{
    /*
        Para convertir un string a un int, usamos stringstream
        y el operador >> para convertir el string a un int. Ya que 
        convertira la entrada en el tipo de dato que le pasemos.
        Convertimos en string en un long long, para poder
        comprobar si esta en rango de int.
        Raliza operaciones como cin, pero en vez de leer de la entrada
        estandar, lee de un string(es decir, de un buffer de memoria).
        Ya que ./stringstream si se encuentra con un numero que supera
        el rango de int, devolvera el valor maximo o minimo de int.
    */
    double i;
    std::stringstream ss(ref);
    ss >> i;

    //Imprimir el char, si es imprimible
    if(isprint(static_cast<char>(i)) 
        && i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    /*
        Comprobamos si el numero esta en rango de int y lo imprimimos
    */
    if(i > std::numeric_limits<int>::min() && i < std::numeric_limits<int>::max()) {
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    }    
    if(i > std::numeric_limits<int>::max()) {
        std::cout << "int: " << "Overflow" << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        if (i == std::numeric_limits<double>::max())
            std::cout << "double: " << "inf" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(i) << std::endl;
    }    
    if(i < std::numeric_limits<int>::min()) {
            std::cout << "int: " << "Underflow" << std::endl;       
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
            if (i == -std::numeric_limits<double>::max())
                    std::cout << "double: " << "-inf" << std::endl;
            else
                    std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
}

void ScalarConverter::printFloat(std::string const &ref)
{
    float f;
    int i;
    double d;
    std::stringstream ss(ref);
    ss >> d;
    i = static_cast<int>(d);
    f = static_cast<float>(d);

    if(isprint(static_cast<char>(i)) 
        && i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if(f > static_cast<float>(std::numeric_limits<int>::min()) && f < static_cast<float>(std::numeric_limits<int>::max()))
        std::cout << "int: " << i << std::endl;
    if(f > static_cast<float>(std::numeric_limits<int>::max())) 
        std::cout << "int: " << "Overflow" << std::endl; 
    if(f < static_cast<float>(std::numeric_limits<int>::min())) 
        std::cout << "int: " << "Underflow" << std::endl;
	
    
    //std::cout << std::fixed << std::setprecision(10); //Diez decimales de precision
	if (f - floorf(f) == 0) // floorf redondea al entero mas cercano, si lo restamos al numero original y da 0, es que es un entero
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

    if (d == std::numeric_limits<double>::max())
        std::cout << "double: " << "inf" << std::endl;
    else if (d == -std::numeric_limits<double>::max())
        std::cout << "double: " << "-inf" << std::endl;
	else if (d - floor(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
 
}

void ScalarConverter::printDouble(std::string const &ref)
{
    float f;
    int i;
    double d;
    std::stringstream ss(ref);
    ss >> d;
    i = static_cast<int>(d);
    f = static_cast<float>(d);

    if(isprint(static_cast<char>(i)) 
        && i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if(d > static_cast<double>(std::numeric_limits<int>::min()) && d < static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: " << i << std::endl;
    if(d > static_cast<double>(std::numeric_limits<int>::max())) 
        std::cout << "int: " << "Overflow" << std::endl; 
    if(d < static_cast<double>(std::numeric_limits<int>::min())) 
        std::cout << "int: " << "Underflow" << std::endl;
	
    //std::cout << std::fixed << std::setprecision(10);
	if (f - floorf(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

    if (d == std::numeric_limits<double>::max())
        std::cout << "double: " << "inf" << std::endl;
    else if (d == -std::numeric_limits<double>::max())
        std::cout << "double: " << "-inf" << std::endl;
	else if (d - floor(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printPseudoDouble(std::string const &ref)
{
    std::cout << "char: Impossible"	<< std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: "	<< ref + "f" << std::endl;
	std::cout << "double: " << ref << std::endl;	
}

void ScalarConverter::printPseudoFloat(std::string const &ref)
{
    std::cout << "char: Impossible"	<< std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: "	<< ref << std::endl;
    std::cout << "double: " << ref.substr(0, ref.size() - 1) << std::endl;	
}

/*************************
* Main - Static function *
*************************/

void ScalarConverter::convert(std::string const &ref)
{
    std::string type = getType(ref);
    std::string types[] = { "char", "int", "float", "double", "pseudo_f", "pseudo_d", "impossible"};
    int i = 0;
    for(i = 0; i < 7; i++)
        if(type == types[i])
            break;
    switch (i)
    {
        case 0:
            printChar(ref);
            break;
        case 1:
            printInt(ref);
            break;
        case 2:
            printFloat(ref);
            break;
        case 3:
            printDouble(ref);
            break;
        case 4:
            printPseudoFloat(ref);
            break;
        case 5:
            printPseudoDouble(ref);
            break;
        default:
            throw ScalarConverter::ImpossibleConversionException();
    }
}