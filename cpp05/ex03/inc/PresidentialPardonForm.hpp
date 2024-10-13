/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:50:41 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/12 17:17:04 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
private:
    std::string target_;
    PresidentialPardonForm(const std::string &target);
public:
    virtual ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const &executor) const;

    static  AForm *create(const std::string &target);


};

#endif
