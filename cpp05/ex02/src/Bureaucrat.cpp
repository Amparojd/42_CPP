/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:48:12 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 19:07:48 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"


// Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    validateGrade(grade);
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

////////////////////////////////

// Excepciones
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "The grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "The grade is too low.";
}


// Getters
const std::string& Bureaucrat::getName() const 
{ 
    return name; 
}
int Bureaucrat::getGrade() const 
{ 
    return grade; 
}

// Validar grados
void Bureaucrat::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Incrementar / Decrementar grados
void Bureaucrat::incrementGrade() 
{
    validateGrade(grade - 1);
    grade--;
}

void Bureaucrat::decrementGrade()
{
    validateGrade(grade + 1);
    grade++;
}

// Firmar formulario
void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " could not sign. " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Ejecutar formulario
void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " could not executed " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}