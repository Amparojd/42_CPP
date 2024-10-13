/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:28:42 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 18:04:18 by ampjimen         ###   ########.fr       */
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
    const std::string nombre;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

    void validarGrado(int grade);
public:
    // Excepciones
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "¡El grado es demasiado alto!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "¡El grado es demasiado bajo!";
        }
    };

    // Constructor y destructor
    Form(const std::string &nombre, int gradeToSign, int gradeToExecute);
    ~Form();

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
