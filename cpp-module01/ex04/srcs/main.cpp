/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-26 15:35:31 by ffreze            #+#    #+#             */
/*   Updated: 2024-03-26 15:35:31 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void sed_to_file(const std::string& filename, const std::string& s1, const std::string& s2) 
{
    std::ifstream input(filename.c_str());
    if (!input) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }

    std::ofstream output((filename + ".replace").c_str());
    if (!output) {
        std::cerr << "Error: Could not open output file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        output << line << std::endl;
    }
}

int main(int argc, char* argv[]) 
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    sed_to_file(filename, s1, s2);

    return 0;
}