/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:49:08 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/12 17:15:53 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include <iostream>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();

    static AForm *create(const std::string &target);
    virtual void execute(const Bureaucrat &executor) const;

private:
    const std::string target_; // Asegúrate de que el objetivo esté definido
};

#endif // ROBOTOMYREQUESTFORM_HPP


