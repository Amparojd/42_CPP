/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:47:45 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 19:12:05 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
    const std::string name;
    int               grade;
    
    void validateGrade(int grade);
    Bureaucrat();
  
public:

    // Canonical form
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();
    
    //excepciones
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    //getters
    const std::string& getName() const;
    int getGrade() const;

    //increment and decrement grade
    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &form) const;
    void executeForm(AForm const &form) const;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
