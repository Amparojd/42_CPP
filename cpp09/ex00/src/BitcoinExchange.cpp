/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:50:04 by ampjimen          #+#    #+#             */
/*   Updated: 2024/11/12 20:39:03 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{
    _data = std::map<std::string, double>();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    _data = other._data;
    return *this;
}

//////////////////////////////////////

void BitcoinExchange::printDb() const
{
    std::map<std::string, double>::const_iterator it;
    for (it = _data.begin(); it != _data.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

std::string BitcoinExchange::to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

bool BitcoinExchange::is_leap(int year)
{

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void BitcoinExchange::is_valid_date(std::string date, std::string filename, int line_number) {
    int year, month, day;
    char delimiter1, delimiter2;
    std::stringstream ss(date);

    // Verificar formato de la fecha
    if (!(ss >> year >> delimiter1 >> month >> delimiter2 >> day) || delimiter1 != '-' || delimiter2 != '-' || !ss.eof()) {
        throw std::runtime_error("Error: invalid date format in file " + filename + " at line " + to_string(line_number) + " => " + date);
    }

    // Validar año
    if (year < 2009 || year > 2024) {
        throw std::runtime_error("Error: the year must be between 2009 and 2024 in file " + filename + " at line " + to_string(line_number) + " => " + date);
    }

    // Validar mes
    if (month < 1 || month > 12) {
        throw std::runtime_error("Error: the month must be between 1 and 12 in file " + filename + " at line " + to_string(line_number) + " => " + date);
    }

    // Determinar el número máximo de días en el mes
    int days_in_month;
    if (month == 2) {
        days_in_month = is_leap(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }

    // Validar día
    if (day < 1 || day > days_in_month) {
        throw std::runtime_error("Error: the day is out of valid range for the month in file " + filename + " at line " + to_string(line_number) + " => " + date);
    }
}

void BitcoinExchange::validLineDB(std::string line, std::string filename, int i)
{
    std::string key;
    double value;
    std::stringstream ss(line);
    std::getline(ss, key, ',');
    ss >> value;
    is_valid_date(key, filename, i);
    if (value < 0)
        throw std::runtime_error("Error: the value cannot be less than 0 in file " + filename + " at line " + to_string(i) + " => " + line);
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Error: invalid exchange rate format in file " + filename + " at line " + to_string(i) + " => " + line);
    this->_data[key] = value;
}

void BitcoinExchange::validLineInput(std::string line, std::string filename, int i)
{
    if (line[0] == ' ' || line[0] == '\t')
        throw std::runtime_error("Error: the line cannot start with a space in file " + filename + " at line " + to_string(i) + " => " + line);

    size_t delimiter_pos = line.find(" | ");
    if (delimiter_pos == std::string::npos)
        throw std::runtime_error("Error: the delimiter \" | \" is not found in file " + filename + " at line " + to_string(i) + " => " + line);
    if (std::count(line.begin(), line.end(), ' ') > 2)
        throw std::runtime_error("Error: the delimiter \" | \" is not found in file " + filename + " at line " + to_string(i) + " => " + line);
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    std::stringstream ss(line);

    std::string key;
    double value;
    std::getline(ss, key, '|');
    ss >> value;
    is_valid_date(key, filename, i);
    if (value < 0)
        throw std::runtime_error("Error: the value cannot be less than 0 in file " + filename + " at line " + to_string(i) + " => " + line);
    if (value > 1000)
        throw std::runtime_error("Error: the value cannot be greater than 1000 in file " + filename + " at line " + to_string(i) + " => " + line);
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Error: invalid value format in file " + filename + " at line " + to_string(i) + " => " + line);
    if (_data.find(key) != _data.end())
    {
        std::cout << key << " => " << value << " = " << value * _data[key] << std::endl;
    }
    else
    {
        std::map<std::string, double>::iterator it = _data.lower_bound(key);
        if (it == _data.begin())
            throw std::runtime_error("Error: no exchange rate data available for date " + key + " in file " + filename + " at line " + to_string(i) + " => " + line);
        else
        {
            it--;
            std::cout << key << " => " << value << " = " << value * it->second << std::endl;
        }
    }
}

void BitcoinExchange::parseDbFile(std::string filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    int i = 1;
    try
    {
        if (!file.is_open())
            throw std::runtime_error("Error: could not open file " + filename);
        std::getline(file, line);
        if (line != "date,exchange_rate")
            throw std::runtime_error("Error: invalid header format in file " + filename);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    while (std::getline(file, line))
    {
        i++;
        std::stringstream ss(line);
        if (line.empty())
            continue;
        try
        {
            validLineDB(line, filename, i);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    file.close();
}

void BitcoinExchange::parseInputFile(std::string filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    int i = 1;
    try
    {
        if (!file.is_open())
            throw std::runtime_error("Error: could not open file " + filename);
        std::getline(file, line);
        if (line != "date | value")
            throw std::runtime_error("Error: invalid header format in file " + filename);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    while (std::getline(file, line))
    {
        i++;
        if (line.empty())
            continue;
        try
        {
            validLineInput(line, filename, i);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    file.close();
}
