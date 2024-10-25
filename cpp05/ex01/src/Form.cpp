/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:29:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 19:34:54 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(const std::string &_name, int gradeToSign, int gradeToExecute)
    : _name(_name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form::Form(const Form &other)
    : _name(other._name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned) {
}

Form& Form::operator=(const Form &other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}

//////////////////////////////////////////////////////////////////
// Getters
const std::string& Form::getNombre() const {
    return _name;
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
void Form::validateGrade(int grade) {
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
    out << "Form: " << form.getNombre() << std::endl
        << " Signed:  " << (form.getIsSigned() ? "Yes" : "No") << std::endl
        << " Required grade to sign: " << form.getGradeToSign() << std::endl
        << " Required grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}
