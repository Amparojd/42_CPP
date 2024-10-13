/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:49:36 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/12 17:12:06 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {} // Corregido aquí

RobotomyRequestForm::~RobotomyRequestForm() {}

AForm *RobotomyRequestForm::create(const std::string &target) {
    return new RobotomyRequestForm(target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;

    // Simulación de éxito/fallo
    if (rand() % 2 == 0)
        std::cout << target_ << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << target_ << "." << std::endl;
}
