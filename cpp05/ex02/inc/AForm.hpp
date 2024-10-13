/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:28:42 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 12:44:36 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    const std::string target;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;

    void validateGrade(int grade);
    
public:
    // Excepciones
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // Constructor
    AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute);
    virtual ~AForm();

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;

    // Firmar y ejecutar
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;  // Clase abstracta

protected:
    void checkExecution(const Bureaucrat &executor) const;  // Método para verificar si puede ejecutarse

};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif

