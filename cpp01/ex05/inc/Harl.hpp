/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:23:44 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/12 21:03:28 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    void complain( std::string level );
};

#endif
