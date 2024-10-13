/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:29:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 18:08:44 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"


// Excepciones
const char* AForm::GradeTooHighException::what() const throw() {
    return "El grado es demasiado alto";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "El grado es demasiado bajo";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "El formulario no está firmado";
}

// Constructor
AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute)
    : name(name), target(target), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

// Destructor
AForm::~AForm() {}

// Validar grados
void AForm::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Getters
const std::string& AForm::getName() const 
{ 
    return name;
}
bool AForm::isSigned() const 
{ 
    return signedStatus;
}
int AForm::getGradeToSign() const 
{ 
    return gradeToSign; 
}
int AForm::getGradeToExecute() const 
{ 
    return gradeToExecute;
}
const std::string& AForm::getTarget() const 
{ 
    return target; 
}

// Firmar formulario
void AForm::beSigned(const Bureaucrat &bureaucrat) 
{
    if (bureaucrat.getGrade() > gradeToSign) 
    
    {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

// Verificación de ejecución
void AForm::checkExecution(const Bureaucrat &executor) const {
    if (!signedStatus) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute) {
        throw GradeTooLowException();
    }
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const AForm &form) {
    out << "Formulario: " << form.getName() << ", objetivo: " << form.getTarget() << std::endl
        << " Firmado: " << (form.isSigned() ? "sí" : "no") <<std::endl
        << " Grado necesario para firmar: " << form.getGradeToSign() <<std::endl
        << " Grado necesario para ejecutar: " << form.getGradeToExecute() <<std::endl;
    return out;
}

