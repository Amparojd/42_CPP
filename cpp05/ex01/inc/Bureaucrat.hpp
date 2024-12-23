/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:47:45 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/25 20:56:49 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

#define HIGH 1
#define LOW 150

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

    void validateGrade(int grade);

    Bureaucrat();
public:
    // Constructor
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();

    // Exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Grade is too low!";
        }
    };

    // Getters
    const std::string &getName() const;
    int getGrade() const;

    // Member functions to increment and decrement the grade
    void incrementGrade();
    void decrementGrade();

    // new function ex01
    void signForm(Form &form) const;
};

// Overloading the insertion operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
