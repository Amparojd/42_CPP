/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:42:33 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/12 17:07:50 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string target_;
public:
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const &executor) const;
    
    static AForm* create(const std::string &target); // Nuevo método estático

};  

#endif
