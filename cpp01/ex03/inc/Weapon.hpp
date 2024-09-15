/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:17:14 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/31 21:34:45 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
    std::string type;

public:
    Weapon();
    Weapon(const std::string& type);
    ~Weapon();
    
    const std::string& getType() const;
    void setType(const std::string& type);
};

#endif
