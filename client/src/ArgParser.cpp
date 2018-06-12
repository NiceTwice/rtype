//
// ArgParser.cpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/src
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include "ArgParser.hpp"

ArgParser::ArgParser()
{

}

ArgParser::~ArgParser()
{
	
}

const char *ArgParser::_getArg(int i, int argc, char **argv)
{
	if (i >= argc)
		return (NULL);
	return (argv[i]);
}

const char *ArgParser::getIp(int argc, char **argv)
{
	return (ArgParser::_getArg(1, argc, argv));
}

uint16_t ArgParser::getPort(int argc, char **argv)
{
	const char *port = ArgParser::_getArg(2, argc, argv);
	char *ptr = NULL;
	long int tmp;

	if (port == NULL)
		return (0);
	tmp = strtol(port, &ptr, 10);
	if (ptr[0] == 0)
		return ((tmp > 0 && tmp <= USHRT_MAX) ? ((uint16_t)tmp) : 0);
	return (0);
}