/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:22:28 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/11 18:49:18 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream>  // Necesario para std::ostringstream

class Zombie {
private:
    std::string name;

public:
    Zombie();  // Constructor 
    Zombie(std::string name);  // Constructor 
    ~Zombie();  // Destructor

    void setName(std::string name); 
    void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
