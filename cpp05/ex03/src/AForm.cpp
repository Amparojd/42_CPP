/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:29:03 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 20:32:19 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"


AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name_(other.name_), 
    signed_(other.signed_), 
    signGrade_(other.signGrade_),
    execGrade_(other.execGrade_) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        signed_ = other.signed_;
    }
    return *this;
}

AForm::~AForm() {}


/////////////////////////////////////7


const std::string &AForm::getName() const {
    return name_;
}

bool AForm::isSigned() const {
    return signed_;
}

int AForm::getSignGrade() const {
    return signGrade_;
}

int AForm::getExecGrade() const {
    return execGrade_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > signGrade_)
        throw GradeTooLowException();
    signed_ = true;
}

void AForm::checkExecution(const Bureaucrat &executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }
}