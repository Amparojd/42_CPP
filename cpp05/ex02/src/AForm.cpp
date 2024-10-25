/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:29:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 19:34:54 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"


AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute) 
    : name(name), target(target), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

// Constructor de copia
AForm::AForm(const AForm &other)
    : name(other.name), target(other.target), signedStatus(other.signedStatus),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    // Aquí no necesitas hacer nada más
}

// Operador de asignación
AForm& AForm::operator=(const AForm &other) {
    if (this != &other) {
        // No se puede asignar el _name y el objetivo ya que son const
        signedStatus = other.signedStatus;
        // Las variables gradeToSign y gradeToExecute son const y no se pueden asignar
    }
    return *this;
}

// Destructor virtual
AForm::~AForm() {}

////////////////////////////////////////
// Excepciones
const char* AForm::GradeTooHighException::what() const throw() {
    return "The grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "The grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "The form is not signed";
}



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
    out << "Form: " << form.getName() << ", object: " << form.getTarget() << std::endl
        << " Signed: " << (form.isSigned() ? "Yes" : "No") <<std::endl
        << " Grade required to sign:  " << form.getGradeToSign() <<std::endl
        << " Grade required to execute: " << form.getGradeToExecute() <<std::endl;
    return out;
}

