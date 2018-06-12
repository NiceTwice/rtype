//
// Network.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

class ArgParser
{
public:
	ArgParser();
	~ArgParser();

	static const char *getIp(int, char **);
	static uint16_t getPort(int, char **);

private:
	static const char *_getArg(int, int, char **);
};