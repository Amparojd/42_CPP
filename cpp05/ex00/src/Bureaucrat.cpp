/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:48:12 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 11:49:59 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    validateGrade(grade);
    this->grade = grade;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getter for name
const std::string& Bureaucrat::getName() const 
{
    return name;
}

// Getter for grade
int Bureaucrat::getGrade() const 
{
    return grade;
}

// Function to increment the grade
void Bureaucrat::incrementGrade() 
{
    validateGrade(grade - 1);
    grade--;
}

// Function to decrement the grade
void Bureaucrat::decrementGrade() 
{
    validateGrade(grade + 1);
    grade++;
}

// Function to validate grade limits
void Bureaucrat::validateGrade(int grade) {
    if (grade < HIGH) {
        throw GradeTooHighException();
    } else if (grade > LOW) {
        throw GradeTooLowException();
    }
}

// Overloading the insertion operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}
