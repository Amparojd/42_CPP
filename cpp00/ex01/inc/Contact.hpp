/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:20:41 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/30 18:14:04 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
# include "colors.hpp"

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setFirstName(const std::string& str);
    void setLastName(const std::string& str);
    void setNickname(const std::string& str);
    void setPhoneNumber(const std::string& str);
    void setDarkestSecret(const std::string& str);

    static void getValidInput(const std::string& prompt, std::string& input, \
    const std::string& errorMsg, bool isPhoneNumber = false);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
