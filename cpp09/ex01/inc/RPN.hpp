/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:14:20 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/12 21:00:42 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include  <iostream>
#include  <stack>

class RPN
{
    private:
        std::stack<int> _values;
        std::string _str;
        RPN();
    public:
        RPN(std::string &str);
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        
        
        void calculate();
};
#endif