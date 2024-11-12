/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:15:13 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/12 21:01:08 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"
#include <sstream>


RPN::RPN(std::string &str) : _str(str) {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _str(other._str) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _str = other._str;
    return *this;
}

//////////////////////////////////////////////

bool isNumber(const std::string& token) 
{
    if (token.empty()) 
        return false;
    std::stringstream ss(token);
    double d;
    char c;
   
    if (!(ss >> d) || (ss >> c)) 
    {
        return false;
    }
    return true;
}

double stringToDouble(const std::string& token) 
{
    double value;
    std::stringstream ss(token);
    ss >> value;
    if (ss.fail()) 
    {
        throw std::invalid_argument("Invalid number: " + token);
    }
    return value;
}

void RPN::calculate() 
{
    std::stringstream ss(this->_str);
    std::string token;

    while (ss >> token) 
    {
        if (isNumber(token)) 
        {
            double value = stringToDouble(token);
            if (value > 9 || value < -9) 
            {
                throw std::invalid_argument("Number out of range: " + token);
            }
            this->_values.push(value);
        } 
        else if (token.length() == 1 && std::string("+-*/").find(token) != std::string::npos) 
        {
            
            if (this->_values.size() < 2) 
            {
                throw std::runtime_error("Not enough values for operator: " + token);
            }
            
            double b = this->_values.top();
            this->_values.pop();
            double a = this->_values.top();
            this->_values.pop();
            
            char op = token[0];
            switch (op) {
                case '+':
                    this->_values.push(a + b);
                    break;
                case '-':
                    this->_values.push(a - b);
                    break;
                case '*':
                    this->_values.push(a * b);
                    break;
                case '/':
                    if (b == 0.0) {
                        throw std::runtime_error("Division by zero");
                    }
                    this->_values.push(a / b);
                    break;
                default:
                    throw std::invalid_argument("Unknown operator: " + token);
            }
        } else {
            throw std::invalid_argument("Invalid token: " + token);
        }
    }
    
    if (this->_values.size() != 1) {
        throw std::runtime_error("Invalid RPN expression");
    }
    std::cout << this->_values.top() << std::endl;
}


