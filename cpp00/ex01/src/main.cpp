/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:17:47 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/30 19:39:08 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void addContact(PhoneBook& phoneBook) {
    Contact newContact;
    std::string input;

    Contact::getValidInput("Enter First Name: ", input, "First Name cannot be empty. Please try again.");
    newContact.setFirstName(input);

    Contact::getValidInput("Enter Last Name: ", input, "Last Name cannot be empty. Please try again.");
    newContact.setLastName(input);

    Contact::getValidInput("Enter Nickname: ", input, "Nickname cannot be empty. Please try again.");
    newContact.setNickname(input);

    Contact::getValidInput("Enter Phone Number: ", input, "Phone Number must contain only digits or start with '+'. Please try again.", true);
    newContact.setPhoneNumber(input);

    Contact::getValidInput("Enter Darkest Secret: ", input, "Darkest Secret cannot be empty. Please try again.");
    newContact.setDarkestSecret(input);

    //phoneBook.addContact(newContact);
    int index = phoneBook.addContact(newContact);
    std::cout << GREEN << "Contact added successfully at index - " << index + 1 << " -!" << RESET << std::endl;
    std::cout << std::endl;
}

int main() {
    PhoneBook phoneBook;


    phoneBook.welcome(true);

    std::string command;
    while (true) {
        std::cout << PURPLE << "What would you like to do?  " << RESET ;
        if (!std::getline(std::cin, command)) {
            std::cout << std::endl << "bye 🖐️" << std::endl;
            break;
        }
        if (command == "ADD") {
            addContact(phoneBook);
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
            if (phoneBook.getContactCount() > 0) { 
                std::cout << PURPLE << "Enter index to display: "<< RESET;
                if (!std::getline(std::cin, command)) {
                    std::cout << std::endl << "bye 🖐️" << std::endl;
                    break;
                }
                phoneBook.displayContact(std::atoi(command.c_str()));
            }    
        } else if (command == "EXIT") {
            std::cout << "bye 🖐️" << std::endl;
            break;
        } else {
            std::cout << std::endl;
            std::cout << RED << "That option is not available, please try again" << RESET << std::endl;
            std::cout << std::endl;
            phoneBook.welcome(false);
        }
    }

    return 0;
}
