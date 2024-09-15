/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:19:16 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/31 19:50:39 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//constructor and initialization list
PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

int PhoneBook::getContactCount() const {
    return contactCount;
}

void PhoneBook::welcome(bool print_welcome) const {
    if (print_welcome) {
        std::cout << std::endl;
        std::cout << GREEN << "Welcome to the wonderful phone book!" << RESET << std::endl;
        std::cout << std::endl;
    }
    std::cout << CYAN << "    ***** TOOLS *****   " << RESET << std::endl;
    std::cout << PURPLE << "ADD\t:"<< RESET << "  📝 To add a contact." << std::endl;
    std::cout << PURPLE << "SEARCH\t:" << RESET << "  🔍 To search for a contact." << std::endl;
    std::cout << PURPLE << "EXIT\t:" << RESET << "  🏃 To quit the PhoneBook." << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

// Añade un contacto y retorna el índice
int PhoneBook::addContact(const Contact& contact) {
    int index;
    if (contactCount < 8) {
        contacts[contactCount] = contact;
        index = contactCount;
        contactCount++;
    } else {
        index = oldestContactIndex;
        contacts[oldestContactIndex] = contact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
    return index;
}

std::string PhoneBook::truncateString(const std::string& str, int width) {
    std::string::size_type strLength = str.length();
    std::string::size_type maxWidth = static_cast<std::string::size_type>(width);
    
    if (strLength > maxWidth) {
        return str.substr(0, maxWidth - 1) + "."; // Truncar y añadir punto
    }
    return str;
}

void PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << RED << "The phonebook is empty. No contacts to display." << RESET << std::endl;
        return;
    }
    std::cout << std::setw(fieldWidth) << "Index" << "|"
              << std::setw(fieldWidth) << "First Name" << "|"
              << std::setw(fieldWidth) << "Last Name" << "|"
              << std::setw(fieldWidth) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(fieldWidth) << i + 1 << "|"
                  << std::setw(fieldWidth) << truncateString(contacts[i].getFirstName(), fieldWidth) << "|"
                  << std::setw(fieldWidth) << truncateString(contacts[i].getLastName(), fieldWidth) << "|"
                  << std::setw(fieldWidth) << truncateString(contacts[i].getNickname(), fieldWidth) << "|" << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 1 || index > contactCount) {
        std::cout << RED << "Invalid index" << RESET << std::endl;
        return;
    }

    const Contact& contact = contacts[index - 1];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
