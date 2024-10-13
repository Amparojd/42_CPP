/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:49:08 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/12 16:50:20 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>  // Para rand()
#include <iostream>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const &executor) const;
};

#endif

