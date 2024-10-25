/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:28:42 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 20:08:39 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name_;
    bool              signed_;
    const int         signGrade_;
    const int         execGrade_;
    std::string       _target;
    
public:

    AForm(const std::string &name, int signGrade, int execGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();
    
    class GradeTooHighException : public std::exception {
        const char* what() const throw() {
            return "Grade is too high!";
        }
    };
    
    class GradeTooLowException : public std::exception {
        const char* what() const throw() {
            return "Grade is too low!";
        }
    };

    class FormNotSignedException : public std::exception {
        const char* what() const throw() {
            return "Form is not signed!";
        }
    };

    //Getters
    const std::string &getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;
    void checkExecution(const Bureaucrat &executor) const;
};

#endif
