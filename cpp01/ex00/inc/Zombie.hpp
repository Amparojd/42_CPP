/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:58:55 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/11 18:32:54 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);  // Constructor
    ~Zombie();  // Destructor

    void announce(void); 
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
