/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:28:42 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 20:57:00 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
private:
    const std::string _name;
    const int         gradeToSign;
    const int         gradeToExecute;
    bool              isSigned;
    void validateGrade(int grade);
    Form();
public:

    Form(const std::string &_name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form& operator=(const Form &other);
    ~Form();
    
    // Excepciones
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };


    // Getters
    const std::string& getNombre() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Funciones
    void beSigned(const Bureaucrat &bureaucrat);

};

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream &out, const Form &form);

#endif
