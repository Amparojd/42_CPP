/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:29:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/21 19:59:31 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

// Constructor
Form::Form(const std::string &nombre, int gradeToSign, int gradeToExecute)
    : nombre(nombre), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    validarGrado(gradeToSign);
    validarGrado(gradeToExecute);
}

// Destructor
Form::~Form() {}

// Getters
const std::string& Form::getNombre() const {
    return nombre;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

// Función para validar los grados
void Form::validarGrado(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Función para que el formulario sea firmado por un burócrata
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream &out, const Form &form) {
    out << "Formulario: " << form.getNombre() << std::endl
        << " Firmado: " << (form.getIsSigned() ? "sí" : "no") << std::endl
        << " Grado requerido para firmar: " << form.getGradeToSign() << std::endl
        << " Grado requerido para ejecutar: " << form.getGradeToExecute() << std::endl;
    return out;
}
