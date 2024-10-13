/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:43:00 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 18:07:08 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);
    
    std::ofstream ofs((getTarget() + "_shrubbery").c_str());
    if (ofs.fail()) {
        std::cerr << "Error al crear el archivo" << std::endl;
        return;
    }
    ofs << "       _-_       " << std::endl;
    ofs << "    /~~   ~~\\    " << std::endl;
    ofs << " /~~         ~~\\ " << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  / " << std::endl;
    ofs << "   ~  \\\\ //  ~   " << std::endl;
    ofs << "_- -   | | _- _  " << std::endl;
    ofs << "  _ -  | |   -_  " << std::endl;
    ofs << "       // \\\\     " << std::endl;
    ofs.close();
}
