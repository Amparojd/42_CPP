/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:52:25 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/12 20:29:17 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    // Open the original file
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    // Read the entire file content into a string
    std::ostringstream oss;
    oss << inputFile.rdbuf();
    std::string fileContent = oss.str();
    inputFile.close();

    // Perform the replacement
    std::string::size_type pos = 0;
    while ((pos = fileContent.find(s1, pos)) != std::string::npos) {
        fileContent.replace(pos, s1.length(), s2);
        pos += s2.length();
    }

    // Write the modified content to a new file
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: Cannot create file " << filename << ".replace" << std::endl;
        return;
    }
    outputFile << fileContent;
    outputFile.close();
}
