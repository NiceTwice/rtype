//
// Printer.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include <string>

class Printer
{
public:
	static void info(const std::string &);
	static void warning(const std::string &);
	static void error(const std::string &);
};