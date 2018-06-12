//
// Printer.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include "Printer.hpp"

void Printer::info(const std::string &message)
{
	std::cout << "[INFO] " << message << std::endl;
}

void Printer::warning(const std::string &message)
{
	std::cerr << "[WARNING] " << message << std::endl;
}

void Printer::error(const std::string &message)
{
	std::cerr << "[ERROR] " << message << std::endl;
}