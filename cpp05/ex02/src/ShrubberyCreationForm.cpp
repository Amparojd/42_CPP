/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:43:00 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 19:22:11 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", target, 145, 137) {}



ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/////////////////////////////////////////////////////////////////////////////

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    
    checkExecution(executor);
    system("cat home_shrubbery");

    std::string fileName = getTarget() + "_shrubbery";
    std::ofstream out(fileName.c_str());
    if (out.fail()) {
        std::cerr << "Error creating the file." << std::endl;
    }
    
    out << "       _-_       " << std::endl;
    out << "    /~~   ~~\\    " << std::endl;
    out << " /~~         ~~\\ " << std::endl;
    out << "{               }" << std::endl;
    out << " \\  _-     -_  / " << std::endl;
    out << "   ~  \\\\ //  ~   " << std::endl;
    out << "_- -   | | _- _  " << std::endl;
    out << "  _ -  | |   -_  " << std::endl;
    out << "       // \\\\     " << std::endl;
    
    out.close();

}