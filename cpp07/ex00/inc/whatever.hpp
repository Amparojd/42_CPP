/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:27:30 by ampjimen          #+#    #+#             */
/*   Updated: 2024/10/28 18:38:31 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Define colors
#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define YELLOW      "\033[93m"
#define CYAN        "\033[96m"
#define PURPLE      "\033[95m"
#define GRAY        "\033[90m"
#define BOLD        "\033[1m"
#define ITALIC      "\033[3m"

//swap
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
//min value
template <typename T>
T min(const T &a, const T &b)
{
    if (a == b) {
        std::cout << PURPLE << "min: Both values are equal, returning the second one." << RESET << std::endl;
    }
    return (a < b) ? a : b;
}

//max value
template <typename T>
T max(const T &a, const T &b)
{
    if (a == b) {
        std::cout << PURPLE << "max: Both values are equal, returning the second one." << RESET << std::endl;
    }
    return (a > b) ? a : b;
}
#endif