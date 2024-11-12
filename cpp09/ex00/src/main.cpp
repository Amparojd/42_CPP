/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:50:25 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/04 20:00:18 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"


int main(int argc, char **argv)
{

    std::string filename;
    if (argc != 2) 
    {
        std::cerr << "Error: invalid number of arguments." << std::endl;
        std::cout << "Try: ./btc [input file]" << std::endl;
        return 1;
    }
    filename = argv[1];
    BitcoinExchange exchange = BitcoinExchange();
    exchange.parseDbFile("data.csv");
    exchange.parseInputFile(filename);
    return 0;
}
