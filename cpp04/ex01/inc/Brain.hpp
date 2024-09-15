/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:39:38 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:39:45 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain &other);
    ~Brain();

    Brain& operator=(const Brain &other);
    std::string ideas[100];

private:
    void copyIdeas(const Brain &other);
};

#endif
