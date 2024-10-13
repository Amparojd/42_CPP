/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:49:36 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/12 16:50:13 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);
    std::cout << "* ruidos de taladro *" << std::endl;
    
    if (rand() % 2) {
        std::cout << getTarget() << " ha sido robotomizado con éxito." << std::endl;
    } else {
        std::cout << "La robotomización de " << getTarget() << " ha fallado." << std::endl;
    }
}