/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:20:59 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/29 20:54:02 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int fieldWidth = 10;
    Contact contacts[8];
    int contactCount;
    int oldestContactIndex;

    static std::string truncateString(const std::string& str, int width);

public:
    PhoneBook();
    int getContactCount() const;
    int addContact(const Contact& contact);
    void searchContacts() const;
    void displayContact(int index) const;
    void welcome(bool print_welcome) const;
};

#endif
