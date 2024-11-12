/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:49:32 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/12 20:33:43 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double>  _data;       
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        
        
        void parseDbFile(std::string filename);
        void parseInputFile(std::string filename);

        std::string to_string(int i);
        void validLineDB(std::string line, std::string filename, int i);
        void validLineInput(std::string line, std::string filename, int i);
        void is_valid_date(std::string date, std::string filename, int i);
        bool is_leap(int year);

        void printDb() const;   
};

#endif
