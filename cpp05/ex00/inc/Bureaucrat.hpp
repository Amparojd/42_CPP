/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:47:45 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/13 11:40:01 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

#define HIGH 1
#define LOW 150

// Define colors
#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define CYAN        "\033[96m"
#define PURPLE      "\033[95m"
#define GRAY        "\033[90m"
#define BOLD        "\033[1m"
#define ITALIC      "\033[3m"

class Bureaucrat {
private:
    const std::string name;
    int grade;

    void validateGrade(int grade);
public:
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };

    // Constructor and destructor
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Member functions to increment and decrement the grade
    void incrementGrade();
    void decrementGrade();

};

// Overloading the insertion operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
