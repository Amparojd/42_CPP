/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:42:10 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/28 18:50:09 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T* array, std::size_t length, void (*func)(T&))
{
    for(std::size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

template <typename T>
void print(T& value) {
    std::cout << value << " ";
}

#endif