/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:19:47 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/31 19:50:27 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*Validations*/
bool isValidPhoneNumber(const std::string& str) {
    if (str.empty()) return false;

    size_t startIndex = 0;
    if (str[0] == '+') {
        if (str.length() == 1) return false;
        startIndex = 1;
    }

    for (size_t i = startIndex; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

void Contact::getValidInput(const std::string& prompt, std::string& input, const std::string& errorMsg, bool isPhoneNumber) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl << "bye 🖐️" << std::endl;
            exit(0);
        }

        if (isPhoneNumber) {
            if (isValidPhoneNumber(input)) {
                break;
            }
            std::cout << RED << "ERROR: " << errorMsg << RESET << std::endl;
        } else {
            if (!input.empty()) {
                break;
            }
            std::cout << RED << "ERROR: " << errorMsg << RESET << std::endl;
        }
    }
}

void Contact::setFirstName(const std::string& str) {
    firstName = str;
}

void Contact::setLastName(const std::string& str) {
    lastName = str;
}

void Contact::setNickname(const std::string& str) {
    nickname = str;
}

void Contact::setPhoneNumber(const std::string& str) {
    phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string& str) {
    darkestSecret = str;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
